#include "messaging.h"
#include <msgpck.h>
#include "my_stream.hpp"
#include "ui_custom.h"

void msg_receive(uint8_t * payload, size_t length) {

    MyStream ms((const char* const)payload, length);

    uint32_t array_size;

    bool res = true;

    res &= msgpck_array_next(&ms);
    if(!res) {
        ui_writeLog("msgpack read failed: expected array");
        return;
    }

    res &= msgpck_read_array_size(&ms, &array_size);
    if(!res) {
        ui_writeLog("msgpack read failed: array size cant be read");
        return;
    }

    res &= (array_size == 6);
    if(!res) {
        ui_writeLog("msgpack read failed: expected array size of 6");
        return;
    }

    uint8_t indices[array_size];
    bool states[array_size];

    for(int i = 0; i < array_size; i++) {
        res &= msgpck_read_integer(&ms, &indices[i], 1);
        if(!res) {
            ui_writeLog("msgpack read failed");
        }
        res &= msgpck_read_bool(&ms, &states[i]);
        if(!res) {
            ui_writeLog("msgpack read failed");
        }
    }

    char buffer[30];
    sprintf(buffer, "relais states: %d %d %d %d %d %d \n", states[0], states[1], states[2], states[3], states[4], states[5]);
    auto fromBuf = std::string(buffer, 30);

    ui_writeLog(fromBuf);
}