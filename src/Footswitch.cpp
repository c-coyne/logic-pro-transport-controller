/*=====================================================================================*\
| Author:   Christopher Coyne                                         March 13th, 2024  |
| --------------------------------------------------------------------------------------|
| Date:     March 13th, 2024                                                            |
| --------------------------------------------------------------------------------------|
| MODULE:     [ Footswitch ]                                                            |
| --------------------------------------------------------------------------------------|
| DESCRIPTION:                                                                          |
|    Footswitch class                                                                   |
| --------------------------------------------------------------------------------------|
\*=====================================================================================*/

/****************************************************
 *  Include files                                   *
 ****************************************************/
#include "Footswitch.h"
#include "Cfg_Types.h"
#include <Arduino.h>

/****************************************************
 *  Constructor / destructor                        *
 ****************************************************/

Footswitch::Footswitch(int switchPins[4])
           : switch0(0, switchPins[0]),
             switch1(1, switchPins[1]),
             switch2(2, switchPins[2]),
             switch3(3, switchPins[3]) {
    for (int i=0; i<4; i++) {
        pinMode(switchPins[i], INPUT_PULLUP);
    }
}

Footswitch::~Footswitch() {}

/****************************************************
 *  Member functions                                *
 ****************************************************/

SwitchID Footswitch::checkSwitches() {

    if (switch0.isPressed()) {
        int count_ms = 0;
        while (switch0.isPressed() && (count_ms < 1000)) {
            count_ms++;
            delay(1);
        }
        return (count_ms == 1000) ? SWITCH_0_LONG : SWITCH_0; // If Switch 0 pressed for more than 1 second, send long press 
                                                              // on rising edge. Otherwise send normal press on rising edge
    }
    if (switch1.isPressed()) { 
        while (switch1.isPressed()) { delay(1); } // Send response on rising edge
        return SWITCH_1;
    }
    if (switch2.isPressed()) {
        while (switch2.isPressed()) { delay(1); } // Send response on rising edge
        return SWITCH_2;
    }
    if (switch3.isPressed()) { 
        while (switch3.isPressed()) { delay(1); } // Send response on rising edge
        return SWITCH_3;
    }

    return SWITCH_NONE;
}