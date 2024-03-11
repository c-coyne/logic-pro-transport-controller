#ifndef CFG_TYPES_H
#define CFG_TYPES_H

/****************************************************
 *  Local defines                                   *
 ****************************************************/
// LEDController
#define LED_PIN             6
#define NUM_LEDS            58
#define BRIGHTNESS          128
#define LED_TYPE            WS2811
#define COLOR_ORDER         GRB
#define UPDATES_PER_SECOND  100

#define SWITCH0_COLOR       CRGB::Blue
#define SWITCH1_COLOR       CRGB::Green
#define SWITCH2_COLOR       CRGB::Orange
#define SWITCH3_COLOR       CRGB::Red

#define SWITCH0_PIN         2
#define SWITCH1_PIN         3
#define SWITCH2_PIN         4
#define SWITCH3_PIN         5

// Micro
enum State {
    STATE_INIT,
    STATE_START,
    STATE_PLAY,
    STATE_STOP,
    STATE_RECORD,
    STATE_ERR
};

enum SwitchID {
    SWITCH_INIT,
    SWITCH_0,
    SWITCH_1,
    SWITCH_2,
    SWITCH_3,
    SWITCH_NONE
};

// SerialCommunication
#define SERIAL_ENABLED      false   // Turn serial communication on/off
// START - Return key
#define SWITCH0_MACCMD      false   // Mac Command key not pressed
#define SWITCH0_COMMAND     36      // Return key
// PLAY - space bar
#define SWITCH1_MACCMD      false   // Mac Command key not pressed
#define SWITCH1_COMMAND     32      // Space bar
// STOP - space bar
#define SWITCH2_MACCMD      false   // Mac Command key not pressed
#define SWITCH2_COMMAND     32      // Space bar
// RECORD - r
#define SWITCH3_MACCMD      false   // Mac Command key not pressed
#define SWITCH3_COMMAND     114     // r key

#endif // CFG_TYPES_H