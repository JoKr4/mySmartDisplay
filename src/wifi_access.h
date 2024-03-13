#pragma once

#include <WiFi.h>
#include "lvgl.h"
#include "secrets.h"
#include "ui_custom.h"
#include <string>

char ssid[] = SECRET_SSID;
char psk[] = SECRET_PSK;

void connect_wifi() {

    WiFi.begin(ssid, psk);

    ui_writeLog("connecting wifi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }
    ui_writeLog("ok");

    std::string log("ip is ");
    log += WiFi.localIP().toString().c_str();
    ui_writeLog(log);
}
