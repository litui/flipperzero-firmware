#pragma once
#include "dtmf_dolphin_hal.h"
#include "tones/dtmf_dolphin_bluebox_tones.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    DTMF_DOLPHIN_TONE_BLOCK_BLUEBOX,
    DTMF_DOLPHIN_TONE_BLOCK_REDBOX,
} DTMFDolphinToneSection;

const char* dtmf_dolphin_get_tone_name(uint8_t index, DTMFDolphinToneSection block);

// void dtmf_dolphin_bluebox_generate(uint8_t index, uint8_t *buffer);

#ifdef __cplusplus
}
#endif
