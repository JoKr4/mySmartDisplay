#pragma once 

#include <Arduino.h>
#include <HTTPClient.h>
#include "lvgl.h"
#include "msgpck.h"

static HTTPClient httpClient;

void http_init() {
    httpClient.begin("http://alarmpi/relais1/state");
}

void http_stop() {
    httpClient.end();
}

void http_get_example() {

    lv_textarea_add_text(ui_TextArea1, "do http request\n");  

    int httpCode = httpClient.GET();

    if(httpCode > 0) {
        if(httpCode == HTTP_CODE_OK) {
            //String payload = http.getString();
            lv_textarea_add_text(ui_TextArea1, "http ok\n");

            // https://registry.platformio.org/libraries/heads-project/Message%20Pack%20for%20Arduino/examples/led_controller/led_controller.ino

            // message form like this {"pin":6, "val":true}

            bool res = true;

            // uint8_t i;
            // char buf[8];
            // uint32_t map_size;
            // uint32_t r_size;
            // uint8_t pin;
            bool level;

            // res &= msgpck_map_next(&httpClient.getStream());
            // if(!res) return;

            // res &= msgpck_map_next(&httpClient.getStream());
            // if(!res) return;

            // res &= msgpck_read_map_size(&httpClient.getStream(), &map_size);
            // if(!res) return;

            // res &= (map_size == 2);
            // res &= msgpck_read_string(&httpClient.getStream(), buf, 3, &r_size);
            // if(!res) return;

            // res &= (buf[0] == 'p');
            // res &= (buf[1] == 'i');
            // res &= (buf[2] == 'n');
            // res &= msgpck_read_integer(&httpClient.getStream(), &pin, 1);
            // if(!res) return;

            // res &= msgpck_read_string(&httpClient.getStream(), buf, 3, &r_size);
            // if(!res) return;

            // res &= (buf[0] == 'v');
            // res &= (buf[1] == 'a');
            // res &= (buf[2] == 'l');
            res &= msgpck_read_bool(&httpClient.getStream(), &level);
            if(!res) return;

            if(level) {
                lv_textarea_add_text(ui_TextArea1, "relais1 state is on\n");
            } else {
                lv_textarea_add_text(ui_TextArea1, "relais1 state is off\n");
            }
        }
    } else {
        lv_textarea_add_text(ui_TextArea1, "http failed\n");
        //Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

}