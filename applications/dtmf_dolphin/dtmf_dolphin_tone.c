#include "dtmf_dolphin_tone.h"

const char* dtmf_dolphin_get_tone_name(uint8_t index, DTMFDolphinToneSection block) {
    if (block == DTMF_DOLPHIN_TONE_BLOCK_BLUEBOX) {
        if (index < DTMF_DOLPHIN_BLUEBOX_TONE_COUNT) {
            return dtmf_dolphin_bluebox_tone[index].name;
        }
    }
    return "None selected.";
}

// void dtmf_dolphin_bluebox_generate(uint8_t index, uint8_t *buffer) {

//     // TODO: Generate the waveform
// }
