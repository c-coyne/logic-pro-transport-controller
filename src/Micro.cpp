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

void Micro::fade(int duration, int times) {
    
    // Set up interval and initial color component
    float interval = 255. / (2 * duration);
    float component = 0;

    // Gradually fade the LED up and down {times} times
    for (int i=0; i<times; i++) {

        // Fade up
        for (int j=0; j<(duration/2); j++) {
            
            // Set the LED color
            CRGB color = CRGB((uint8_t)component, (uint8_t)component, (uint8_t)component);
            ledController.setLEDColor(color);

            // Increment the color component
            component += interval;

            delay(1);
        }

        // Fade down
        for (int j=0; j<(duration/2); j++) {
            
            // Set the LED color
            CRGB color = CRGB((uint8_t)component, (uint8_t)component, (uint8_t)component);
            ledController.setLEDColor(color);

            // Decrement the color component
            component -= interval;

            delay(1);
        }
    }

    // Fade back up to move into the actual program
        for (int j=0; j<(duration/2); j++) {
            
            // Set the LED color
            CRGB color = CRGB((uint8_t)component, (uint8_t)component, (uint8_t)component);
            ledController.setLEDColor(color);

            // Increment the color component
            component += interval;

            delay(1);
        }

}

void Micro::microInit() {

    // Fade LED strip up and down three times
    fade(400, 2);

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
}