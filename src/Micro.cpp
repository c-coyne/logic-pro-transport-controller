/****************************************************
 *  Include files                                   *
 ****************************************************/
#include "Micro.h"
#include <Arduino.h>

Micro::Micro(int switchPins[4]) : footSwitch(switchPins) {
    currentSwitch = 4;
}

Micro::~Micro() {
    // deallocate resources if any
}

void Micro::checkFootswitch() {
    int id = footSwitch.checkSwitches();
    if ((id != 4) && (id != currentSwitch)) {
        currentSwitch = id;
        switch(currentSwitch) {
            case 0:
                ledController.setLEDColor(SWITCH0_COLOR);
                break;
            case 1:
                ledController.setLEDColor(SWITCH1_COLOR);
                break;
            case 2:
                ledController.setLEDColor(SWITCH2_COLOR);
                break;
            case 3:
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