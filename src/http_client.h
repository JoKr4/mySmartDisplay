#pragma once 

#include <Arduino.h>
#include <HTTPClient.h>
#include "lvgl.h"
#include <ArduinoJson.h>

static HTTPClient http;
StaticJsonDocument<200> doc;

void http_init() {
    http.useHTTP10(true);
    http.begin("http://alarmpi/relais1/state");
}

void http_stop() {
    http.end();
}

void http_get_example() {

    lv_textarea_add_text(ui_TextArea1, "do http request\n");  

    int httpCode = http.GET();

    if(httpCode > 0) {
        if(httpCode == HTTP_CODE_OK) {
            //String payload = http.getString();
            lv_textarea_add_text(ui_TextArea1, "http ok\n");

            deserializeJson(doc, http.getStream());
            bool state = doc["state"].as<bool>();
            if(state) {
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