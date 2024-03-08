/****************************************************
 *  Include files                                   *
 ****************************************************/
#include "Switch.h"
#include <Arduino.h>

Switch::Switch(int idValue, int pinValue) : id(idValue), pin(pinValue) {
    // additional initialization if required
}

Switch::~Switch() {
    // deallocate resources if any
}

bool Switch::isPressed() {
    return (digitalRead(pin) == LOW) ? true : false;
}