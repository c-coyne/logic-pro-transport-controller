/****************************************************
 *  Include files                                   *
 ****************************************************/
#include "Micro.h"
#include <Arduino.h>

Micro::Micro(int switchPins[4]) : footSwitch(switchPins) {
    mainSwitch = SwitchID::SWITCH_INIT;
    mainState = State::STATE_INIT;
}

Micro::~Micro() {
    // deallocate resources if any
}

void Micro::fade(int duration, int n, bool increasing, bool endBright) {
    
    // Set up interval and initial color component, initialize fade count
    float interval = float(BRIGHTNESS) / (duration / 2.);
    float brightness = (increasing) ? 0. : float(BRIGHTNESS);
    int count = 0;
    bool countLow = (increasing) ? true : false;

    // Gradually fade the LED up and down {n} times
    while (count < n) {

        ledController.setBrightness(brightness);

        if (increasing) {
            brightness += interval;
            if (brightness > BRIGHTNESS) {
                increasing = false;
                if (!countLow) {count++;}
                }
        } else {
            brightness -= interval;
            if (brightness <= 1) {
                increasing = true;
                if (countLow) {count++;}
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

    // Initialize state machine
    mainState = STATE_INIT;
    mainBrightness = BRIGHTNESS;
    mainInterval = BRIGHTNESS / 500.;

    // Set initial LED brightness and color
    ledController.setBrightness(0);
    ledController.setLEDColor(CRGB::White);
    mainColor = CRGB::White;

    // Fade LED strip up and down two times as init sequence
    fade(300, 2, true, false);

    // Fade LEDs up to BRIGHTNESS to indicate device is ready
    float interval = float(BRIGHTNESS) / 2000.;
    float brightness = 0;
    for (int i=0; i<2001; i++) {
        ledController.setBrightness(brightness);
        brightness += interval;
        delay(1);
    }

}

void Micro::internalFade() {
    // Keep track of whether the LEDs are fading up or down
    static bool increasing = false;

    // Change fade direction if necessary
    if (mainBrightness <= 1) { increasing = true; }
    else if (mainBrightness >= BRIGHTNESS) { increasing = false; }

    // Set brightness of LED string
    mainBrightness = (increasing) ? mainBrightness + mainInterval : mainBrightness - mainInterval;
    ledController.setBrightness(mainBrightness);

    return;
}

void Micro::mainFunction() {

    // Execute per the state machine
    switch(mainState) {
        case STATE_INIT:
            break;
        case STATE_START:
            mainBrightness = BRIGHTNESS;
            break;
        case STATE_PLAY:
            internalFade();
            break;
        case STATE_STOP:
            mainBrightness = BRIGHTNESS;
            break;
        case STATE_RECORD:
            internalFade();
            break;
        default:
            break;
    }
}

void Micro::checkFootswitch() {

    // Poll the footswitch for new input
    int id = footSwitch.checkSwitches();

    // If a switch is pressed, handle it accordingly
    if ((id != SWITCH_NONE) && (id != mainSwitch)) {
        mainSwitch = id;
        switch(mainSwitch) {
            case SWITCH_0: // STATE_START
                mainState = STATE_START;
                ledController.setLEDColor(SWITCH0_COLOR);
                ledController.setBrightness(BRIGHTNESS);
                break;
            case SWITCH_1: // STATE_PLAY
                mainState = STATE_PLAY;
                ledController.setLEDColor(SWITCH1_COLOR);
                ledController.setBrightness(BRIGHTNESS);
                break;
            case SWITCH_2: // STATE_STOP
                mainState = STATE_STOP;
                ledController.setLEDColor(SWITCH2_COLOR);
                ledController.setBrightness(BRIGHTNESS);
                break;
            case SWITCH_3: // STATE_RECORD
                mainState = STATE_RECORD;
                ledController.setLEDColor(SWITCH3_COLOR);
                ledController.setBrightness(BRIGHTNESS);
                break;
            default:
                ledController.setLEDColor(CRGB::White);
                ledController.setBrightness(BRIGHTNESS);
                break;
        }
    }
}