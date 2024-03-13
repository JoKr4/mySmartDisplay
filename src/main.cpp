#include <esp32_smartdisplay.h>
#include "ui_custom.h"
#include "driver/uart.h"
#include "uart.h"
#include "wifi_access.h"
#include "http_client.h"

void setup()
{
  smartdisplay_init();

  auto disp = lv_disp_get_default();
  // lv_disp_set_rotation(disp, LV_DISP_ROT_90);
  lv_disp_set_rotation(disp, LV_DISP_ROT_180);
  // lv_disp_set_rotation(disp, LV_DISP_ROT_270);

  ui_init();

  connect_wifi();

  http_get();
}

void loop()
{
  lv_timer_handler();
}
