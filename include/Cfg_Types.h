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
#define SERIAL_COMS         false    // Turn serial communication on/off
#define SWITCH0_MACCMD      true    // Windows key pressed (example)
#define SWITCH0_COMMAND     98      // b (example)
#define SWITCH1_MACCMD      true    // Windows key pressed (example)
#define SWITCH1_COMMAND     114     // r (example)
#define SWITCH2_MACCMD      false   // Windows key not pressed (example)
#define SWITCH2_COMMAND     50      // 2 (example)
#define SWITCH3_MACCMD      false   // Windows key not pressed (example)
#define SWITCH3_COMMAND     51      // 3 (example)

#endif // CFG_TYPES_H