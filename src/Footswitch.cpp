/****************************************************
 *  Include files                                   *
 ****************************************************/
#include "Footswitch.h"
#include "Cfg_Types.h"
#include <Arduino.h>

Footswitch::Footswitch(int switchPins[4])
           : switch0(0, switchPins[0]),
             switch1(1, switchPins[1]),
             switch2(2, switchPins[2]),
             switch3(3, switchPins[3]) {
    for (int i=0; i<4; i++) {
        pinMode(switchPins[i], INPUT_PULLUP);
    }
}

Footswitch::~Footswitch() {
    // deallocate resources if any
}

SwitchID Footswitch::checkSwitches() {
    if (switch0.isPressed()) {
        int count_ms = 0;
        while (switch1.isPressed() && (count_ms < 1000)) {
            count_ms++;
            delay(1);
        }
        return (count_ms > 1000) ? SWITCH_0_LONG : SWITCH_0;
    }
    if (switch1.isPressed()) { return SWITCH_1; }
    if (switch2.isPressed()) {
        // int count_ms = 0;
        while (switch2.isPressed()) { delay(1); }
        return SWITCH_2;
    }
    if (switch3.isPressed()) { return SWITCH_3; }
    return SWITCH_NONE;
}