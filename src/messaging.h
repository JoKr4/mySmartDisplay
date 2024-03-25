#pragma once

#include <cstddef>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void msg_receive(uint8_t *payload, size_t length);

#ifdef __cplusplus
} /*extern "C"*/
#endif