#pragma once 

#include <Arduino.h>
#include <HTTPClient.h>
#include "lvgl.h"
#include "msgpck.h"
#include "ui_custom.h"

static HTTPClient httpClient;


void http_get() {

    ui_writeLog("do http request");

    httpClient.begin("192.168.178.69", 8090, "/relais/states");

    int httpCode = httpClient.GET();

    if(httpCode > 0) {
        if(httpCode == HTTP_CODE_OK) {
            //String payload = http.getString();
            ui_writeLog("http ok");

            // https://registry.platformio.org/libraries/heads-project/Message%20Pack%20for%20Arduino/examples/led_controller/led_controller.ino

            // message form like this {"pin":6, "val":true}

            bool res = true;

            // uint8_t i;
            // char buf[8];
            uint32_t array_size;
            // uint32_t r_size;
            // uint8_t pin;
            //bool level;

            res &= msgpck_array_next(&httpClient.getStream());
            if(!res) return;

            res &= msgpck_read_array_size(&httpClient.getStream(), &array_size);
            if(!res) return;

            res &= (array_size == 6);
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

            bool all[array_size];

            for(int i = 0; i < array_size; i++) {
                res &= msgpck_read_bool(&httpClient.getStream(), &all[i]);
                if(!res) {
                    ui_writeLog("msgpack read failed");
                }
            }

            char buffer[30];
            sprintf(buffer, "relais states: %d %d %d %d %d %d \n", all[0], all[1], all[2], all[3], all[4], all[5]);
            auto fromBuf = std::string(buffer, 30);

            ui_writeLog(fromBuf);
       
        }
    } else {
        ui_writeLog("http failed");
        //Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    httpClient.end();
}