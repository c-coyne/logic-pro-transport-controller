#ifndef CFG_TYPES_H
#define CFG_TYPES_H

/****************************************************
 *  Local defines                                   *
 ****************************************************/
// LEDController
#define LED_PIN                 6
#define NUM_LEDS                58
#define BRIGHTNESS              128
#define LED_TYPE                WS2811
#define COLOR_ORDER             GRB
#define UPDATES_PER_SECOND      100

#define REWIND_COLOR            CRGB::Indigo
#define START_COLOR             CRGB::Indigo
#define FASTFORWARD_COLOR       CRGB::Indigo
#define PLAY_COLOR              CRGB::Green
#define STOP_COLOR              CRGB::Orange
#define RECORD_COLOR            CRGB::Red

#define SWITCH0_PIN             2
#define SWITCH1_PIN             3
#define SWITCH2_PIN             4
#define SWITCH3_PIN             5

// Micro
enum State {
    STATE_INIT,
    STATE_REWIND,
    STATE_START,
    STATE_FASTFORWARD,
    STATE_PLAY,
    STATE_STOP,
    STATE_RECORD,
    STATE_ERR
};

enum SwitchID {
    SWITCH_INIT,
    SWITCH_0,
    SWITCH_0_LONG,
    SWITCH_1,
    SWITCH_2,
    SWITCH_3,
    SWITCH_NONE
};

// SerialCommunication
#define SERIAL_ENABLED          false   // Turn serial communication on/off
#define REWIND_COMMAND          44      // REWIND: "," key
#define START_COMMAND           36      // START: Return key
#define FASTFORWARD_COMMAND     46      // FAST FORWARD: "." key
#define PLAY_STOP_COMMAND       32      // PLAY / STOP: space bar
#define RECORD_COMMAND          114     // RECORD: "r" key

#endif // CFG_TYPES_H