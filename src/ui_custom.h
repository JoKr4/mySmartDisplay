#pragma once

#include "lvgl.h"
#include <string>

#ifdef __cplusplus
extern "C" {
#endif

void ui_init(void);
void ui_writeLog(const std::string& message);

#ifdef __cplusplus
} /*extern "C"*/
#endif