/*=====================================================================================*\
| Author:   Christopher Coyne                                         March 13th, 2024  |
| --------------------------------------------------------------------------------------|
| MODULE:     **Configuration**                                                         |
| --------------------------------------------------------------------------------------|
| DESCRIPTION:                                                                          |
|    All project configuration done in this file                                        |
| --------------------------------------------------------------------------------------|
\*=====================================================================================*/

#ifndef CFG_TYPES_H
#define CFG_TYPES_H

/****************************************************
 *  Defines                                         *
 ****************************************************/

//----------------- LEDController -----------------//
// Setup
#define LED_PIN                 6
#define NUM_LEDS                58
#define BRIGHTNESS              128
#define LED_TYPE                WS2811
#define COLOR_ORDER             GRB
#define UPDATES_PER_SECOND      100
// State colors
#define INIT_COLOR              CRGB::White
#define REWIND_COLOR            CRGB::Indigo    // [FR_002]
#define START_COLOR             CRGB::Indigo    // [FR_006]
#define FASTFORWARD_COLOR       CRGB::Indigo    // [FR_009]
#define PLAY_COLOR              CRGB::Green     // [FR_013]
#define STOP_COLOR              CRGB::Orange    // [FR_013]
#define RECORD_COLOR            CRGB::Red       // [FR_017]
// Fade
#define FADE_DURATION           1000            // total cycle time in ms

//------------------ Footswitch -------------------//
// Arduino Micro pins
#define SWITCH0_PIN             9
#define SWITCH1_PIN             10
#define SWITCH2_PIN             11
#define SWITCH3_PIN             12

//-------------- SerialCommunication --------------//
// Serial commands
#define SERIAL_ENABLED                  // Turn serial communication on/off
                                        // ASCII:       DEC   HEX   OCT   CHR
                                        // ------------------------------------------
#define REWIND_COMMAND          44      // REWIND       44    2C    054   "," key           [FR_004]
#define START_COMMAND           176     // START        176   B0    260   Return key        [FR_005]
#define FASTFORWARD_COMMAND     46      // FAST FORWARD 46    2E    056   "." key           [FR_011]
#define PLAY_STOP_COMMAND       32      // PLAY / STOP  32    20    040   space bar         [FR_015]
#define RECORD_COMMAND          114     // RECORD       114   72    162   "r" key           [FR_019]

/****************************************************
 *  Structs & enums                                 *
 ****************************************************/

//--------------------- Micro ---------------------//
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

//------------------ Footswitch -------------------//
enum SwitchID {
    SWITCH_INIT,
    SWITCH_0,
    SWITCH_0_LONG,
    SWITCH_1,
    SWITCH_2,
    SWITCH_3,
    SWITCH_NONE
};

#endif // CFG_TYPES_H