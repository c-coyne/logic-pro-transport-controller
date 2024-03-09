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

void Micro::fade(int duration, int n, bool increasing, bool endBright) {
    
    // Set up interval and initial color component, initialize fade count
    float interval = float(BRIGHTNESS) / (duration / 2.);
    float brightness = (increasing) ? 0. : float(BRIGHTNESS);
    int count = 0;

    // Gradually fade the LED up and down {n} times
    while (count < n) {

        ledController.setBrightness(brightness);

        if (increasing) {
            brightness += interval;
            if (brightness > BRIGHTNESS) {increasing = false;}
        } else {
            brightness -= interval;
            if (brightness <= 1) {
                increasing = true;
                count++;
                }
        }

        // Wait 1 ms between cycles
        delay(1);
    }

    // If the LED strip should end bright (vs. dark)
    if (endBright) {       
        
        for (int i=0; i<duration/2; i++) {
            ledController.setBrightness(brightness);
            brightness += interval;
            delay(1);
        }

    }
}

void Micro::microInit() {

    // Set initial LED color and brightness
    ledController.setLEDColor(CRGB::White);
    ledController.setBrightness(0);

    // Fade LED strip up and down three times
    fade(400, 2, true, true);

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