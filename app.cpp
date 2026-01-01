#include "app.h"

#define DEVICE_ADDR "D1:00:22:EA:82:60:3B:9C"


void app_init(void)
{

  cookie_hal_init();
  cookie_hal_delay_ms(1000);
  DW1000Ranging.initCommunication(0, 0, 0);

  char msg[128]; // Buffer para el mensaje
  DW1000.getPrintableDeviceIdentifier(msg);

  volatile int debug_checkpoint = 1;
  DW1000Ranging.startAsResponder(DEVICE_ADDR, DW1000.MODE_1, false, TAG);

}

void app_process_action(void)
{
  DW1000Ranging.loop();
}
