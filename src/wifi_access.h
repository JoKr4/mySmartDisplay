#pragma once

#include <WiFi.h>
#include "lvgl.h"

void connect_wifi() {

    WiFi.begin("secret-SSID", "even-more-secret-PSK");

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }

    auto ip = WiFi.localIP().toString();
    ip += "\n";

    lv_textarea_add_text(ui_TextArea1, ip.c_str());
}
