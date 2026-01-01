#include "cookie_hal.h"
#include "em_gpio.h"
#include "spidrv.h"
#include "sl_udelay.h"

extern SPIDRV_Handle_t sl_spidrv_dw1000_handle;

void cookie_hal_init(void){


  CMU_ClockEnable(cmuClock_GPIO,true); //turns on the pin's clock to make them work.
  //1: Chip select (CS). Output pin (pushPull).
  //DUDA --> QUÉ ES EL CUARTO ARGUMENTO? EL '1'
  GPIO_PinModeSet(DW_CS_PORT, DW_CS_PIN, gpioModePushPull,1);

  GPIO_PinModeSet(DW_EXTON_PORT, DW_EXTON_PIN, gpioModePushPull, 1);
  cookie_hal_delay_ms(50);
  GPIO_PinModeSet(DW_CS_PORT, DW_CS_PIN, gpioModePushPull, 1);

  //2: DW1000 Reset Pin
  GPIO_PinModeSet(DW_RST_PORT, DW_RST_PIN, gpioModeInput, 0);

  // Wakeup: OUTPUT. LOW by default
  GPIO_PinModeSet(DW_WAKE_PORT, DW_WAKE_PIN, gpioModePushPull, 0);

  // IRQ --> Input
  GPIO_PinModeSet(DW_IRQ_PORT, DW_IRQ_PIN, gpioModeInputPull, 0);
}

void cookie_hal_spi_select(bool select){

  if(select == true){
      //This means --> I want to talk through the spi --> Need to clear the pin
      GPIO_PinOutClear(DW_CS_PORT,DW_CS_PIN);
  }
  else{
      //"hanging out" --> Set the pin to high
      GPIO_PinOutSet(DW_CS_PORT,DW_CS_PIN);
  }
}

void cookie_hal_spi_speed(bool fast){
  /*
   * Fast = true --> SPI = 20MHz
   * Fast = false --> SPI at 2 MHz */

  uint32_t bitrate;
  if (fast) {
          bitrate = 16000000; // 16 MHz (Velocidad de crucero)
      } else {
          bitrate = 2000000;  // 2 MHz (Velocidad segura/inicialización)
      }

      // Función del GSDK para cambiar la velocidad al vuelo
      SPIDRV_SetBitrate(sl_spidrv_dw1000_handle, bitrate);
  }

void cookie_hal_spi_transfer(uint8_t *buffer_tx, uint8_t *buffer_rx, uint16_t length) {
    // if buffer_tx == NULL, sends zeros to read.
    // if buffer_rx == NULL, ignores the receiving data.

    //SPIDRV_MTransferB(sl_spidrv_dw1000_handle, buffer_tx, buffer_rx, length);


  // 1. Si la longitud es 0, nos vamos (evita errores tontos)
      if (length == 0) return;

      // 2. Buffers temporales ("Dummy")
      // Usamos static para no reventar la pila si length es grande,
      // pero cuidado con la reentrancia (aquí no hay problema).
      // O mejor, limitamos el tamaño para estar seguros.
      uint8_t dummy_tx[length];
      uint8_t dummy_rx[length];

      uint8_t *tx_ptr = buffer_tx;
      uint8_t *rx_ptr = buffer_rx;

      // 3. Preparar TX: Si es NULL, enviamos ceros (necesario para generar reloj)
      if (buffer_tx == NULL) {
          memset(dummy_tx, 0x00, length);
          tx_ptr = dummy_tx;
      }

      // 4. Preparar RX: Si es NULL, recibimos en el dummy y lo tiramos luego
      if (buffer_rx == NULL) {
          rx_ptr = dummy_rx;
      }

      // 5. Transferencia REAL
      // Importante: Usamos MTransferB (Bloqueante)
      Ecode_t result = SPIDRV_MTransferB(sl_spidrv_dw1000_handle, tx_ptr, rx_ptr, length);

      // 6. (Opcional) Trampa para Debug
      // Si pones un breakpoint aquí y 'result' no es 0 (ECODE_OK),
      // es que el driver está fallando (busy, not init, etc).
      if (result != ECODE_EMDRV_SPIDRV_OK) {
          // ¡Algo va mal en el driver!
          // Breakpoint aquí.
          volatile int error_spi = result;
          (void)error_spi;
      }

}

void cookie_hal_delay_ms(uint32_t ms){
  sl_udelay_wait(ms*1000);
}

void cookie_hal_delay_us(uint32_t us){
  sl_udelay_wait(us);

}

uint32_t cookie_hal_get_millis(void) {

    //Converts sleeptimer ticks to milliseconds.
    uint32_t tick_count = sl_sleeptimer_get_tick_count();
    return sl_sleeptimer_tick_to_ms(tick_count);
}

void cookie_hal_reset(bool active){
    if(active){
        // Queremos resetear: Forzamos salida a 0V (Tierra)
        GPIO_PinModeSet(DW_RST_PORT, DW_RST_PIN, gpioModePushPull, 0);
    }
    else{
        // Soltamos reset: Volvemos a Alta Impedancia (Input)
        GPIO_PinModeSet(DW_RST_PORT, DW_RST_PIN, gpioModeInput, 0);
    }
}
