/****************************************************
 *  Include files                                   *
 ****************************************************/
#include "Micro.h"
#include <Arduino.h>

Micro::Micro(int switchPins[4]) : footSwitch(switchPins) {
    currentSwitch = SwitchID::SWITCH_INIT;
    currentState = State::STATE_INIT;
}

Micro::~Micro() {
    // deallocate resources if any
}

void Micro::checkFootswitch() {
    int id = footSwitch.checkSwitches();
    if ((id != SWITCH_NONE) && (id != currentSwitch)) {
        currentSwitch = id;
        switch(currentSwitch) {
            case SWITCH_0:
                ledController.setLEDColor(SWITCH0_COLOR);
                break;
            case SWITCH_1:
                ledController.setLEDColor(SWITCH1_COLOR);
                break;
            case SWITCH_2:
                ledController.setLEDColor(SWITCH2_COLOR);
                break;
            case SWITCH_3:
                ledController.setLEDColor(SWITCH3_COLOR);
                break;
            default:
                ledController.setLEDColor(CRGB::White);
                break;
        }
    }
    Serial.print("ID detected is: ");
    Serial.println(id);
}