#pragma once

#include <WiFi.h>
#include "lvgl.h"

#include "secrets.h"

char ssid[] = SECRET_SSID;
char psk[] = SECRET_PSK;

void connect_wifi() {

    WiFi.begin(ssid, psk);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }

    auto ip = WiFi.localIP().toString();
    ip += "\n";

    lv_textarea_add_text(ui_TextArea1, ip.c_str());
}
