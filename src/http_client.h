#pragma once 

#include <Arduino.h>
#include <HTTPClient.h>
#include "lvgl.h"

static HTTPClient http;

void http_get_example() {

    lv_textarea_add_text(ui_TextArea1, "do http request\n");

    http.begin("http://192.168.178.21/hello-from-smart-display");

    int httpCode = http.GET();

    if(httpCode > 0) {
        if(httpCode == HTTP_CODE_OK) {
            //String payload = http.getString();
            lv_textarea_add_text(ui_TextArea1, "http ok\n");
        }
    } else {
        lv_textarea_add_text(ui_TextArea1, "http failed\n");
        //Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
}