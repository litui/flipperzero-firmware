#include <stdint.h>

#define DTMF_DOLPHIN_DIALER_TONE_COUNT 16

typedef struct {
    const char *name;
    const float frequency_1;
    const float frequency_2;
} DTMFDolphinDialerTones;

/*  Via https://en.wikipedia.org/wiki/Dual-tone_multi-frequency_signaling
        1209 Hz 	1336 Hz 	1477 Hz 	1633 Hz
697 Hz 	1 	        2 	        3 	        A
770 Hz 	4 	        5 	        6 	        B
852 Hz 	7 	        8 	        9 	        C
941 Hz 	* 	        0 	        # 	        D */

static const DTMFDolphinDialerTones dtmf_dolphin_dialer_tone[DTMF_DOLPHIN_DIALER_TONE_COUNT] = {
    {"1", 697.0, 1209.0},
    {"2", 697.0, 1336.0},
    {"3", 697.0, 1477.0},
    {"A", 697.0, 1633.0},
    {"4", 770.0, 1209.0},
    {"5", 770.0, 1336.0},
    {"6", 770.0, 1477.0},
    {"B", 770.0, 1633.0},
    {"7", 852.0, 1209.0},
    {"8", 852.0, 1336.0},
    {"9", 852.0, 1477.0},
    {"C", 852.0, 1633.0},
    {"*", 941.0, 1209.0},
    {"0", 941.0, 1336.0},
    {"#", 941.0, 1477.0},
    {"D", 941.0, 1633.0},
};
