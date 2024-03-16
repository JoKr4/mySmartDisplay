#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void http_req_relais_states(void);
void http_req_relais_toggle(uint32_t id);

#ifdef __cplusplus
} /*extern "C"*/
#endif