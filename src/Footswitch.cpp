/****************************************************
 *  Include files                                   *
 ****************************************************/
#include "Footswitch.h"
#include "Cfg_Types.h"
#include <Arduino.h>

Footswitch::Footswitch(int switchPins[4])
           : switch1(0, switchPins[0]),
             switch2(1, switchPins[1]),
             switch3(2, switchPins[2]),
             switch4(3, switchPins[3]) {
    for (int i=0; i<4; i++) {
        pinMode(switchPins[i], INPUT_PULLUP);
    }
}

Footswitch::~Footswitch() {
    // deallocate resources if any
}

SwitchID Footswitch::checkSwitches() {
    if (switch1.isPressed()) {return SWITCH_0;}
    if (switch2.isPressed()) {return SWITCH_1;}
    if (switch3.isPressed()) {return SWITCH_2;}
    if (switch4.isPressed()) {return SWITCH_3;}
    return SWITCH_NONE;
}