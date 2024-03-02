#include <esp32_smartdisplay.h>
#include "ui.h"
#include "driver/uart.h"
#include "uart.h"
#include "wifi_access.h"
#include "http_client.h"

void setup()
{

  // uart_config_t uart_config = {
  //       .baud_rate = 115200,
  //       .data_bits = UART_DATA_8_BITS,
  //       .parity    = UART_PARITY_DISABLE,
  //       .stop_bits = UART_STOP_BITS_1,
  //       .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
  //       .source_clk = UART_SCLK_APB,
  // };

  // uart_driver_install(UART_PORT, BUF_SIZE * 2, 0, 0, NULL, 0);
  // uart_param_config(UART_PORT, &uart_config);
  // uart_set_pin(UART_PORT, UART_PIN_RX, UART_PIN_TX, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);

  smartdisplay_init();

  auto disp = lv_disp_get_default();
  // lv_disp_set_rotation(disp, LV_DISP_ROT_90);
  // lv_disp_set_rotation(disp, LV_DISP_ROT_180);
  lv_disp_set_rotation(disp, LV_DISP_ROT_270);

  ui_init();

  connect_wifi();

  http_get();
}

void loop()
{
  lv_timer_handler();
}
