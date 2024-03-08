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
    Serial.print("ID detected is: ");
    Serial.println(id);
}