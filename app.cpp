#include "app.h"

#define DEVICE_ADDR "D1:00:22:EA:82:60:3B:9C"


void dw1000Interrupt(uint8_t pin){

  uint8_t interrupting_pin = pin;

  DW1000.handleInterrupt();
}
void app_init(void)
{

  cookie_hal_init();
  cookie_hal_delay_ms(1000);

  cookie_hal_reset(true);
  cookie_hal_delay_ms(10);
  cookie_hal_reset(false);
  cookie_hal_delay_ms(100);

  GPIOINT_Init();

  GPIO_ExtIntConfig(DW_IRQ_PORT,DW_IRQ_PIN,DW_IRQ_PIN,true,false,true);
  // Port - pin - interruption number same as pin number - ¿Rising edge? - ¿Falling edge? - ¿Enabled?

  GPIOINT_CallbackRegister(DW_IRQ_PIN,dw1000Interrupt);

  DW1000Ranging.initCommunication(DW_RST_PIN , DW_CS_PIN,DW_IRQ_PIN);

  char msg[128]; // Buffer para el mensaje
  DW1000.getPrintableDeviceIdentifier(msg);

  volatile int debug_checkpoint = 1;
  DW1000Ranging.startAsResponder(DEVICE_ADDR, DW1000.MODE_1, false, TAG);

}

void app_process_action(void)
{
  DW1000Ranging.loop();
}
