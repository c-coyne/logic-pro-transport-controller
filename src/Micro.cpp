/****************************************************
 *  Include files                                   *
 ****************************************************/
#include "Micro.h"
#include <Arduino.h>
#include <Keyboard.h>

Micro::Micro(int switchPins[4]) : footSwitch(switchPins) {
    mainSwitch = SwitchID::SWITCH_INIT;
    mainState = State::STATE_INIT;
}

Micro::~Micro() {
    // deallocate resources if any
}

void Micro::microInit() {

    // Initialize state machine
    mainState = STATE_INIT;
    
    // Initialize LED string
    ledController.LEDControllerInit();

    return;
}

void Micro::mainFunction() {

    // Execute per the state machine
    switch(mainState) {
        case STATE_INIT:
            break;
        case STATE_START:
            ledController.mainBrightness = BRIGHTNESS;
            break;
        case STATE_PLAY:
            ledController.internalFade();
            break;
        case STATE_STOP:
            ledController.mainBrightness = BRIGHTNESS;
            break;
        case STATE_RECORD:
            ledController.internalFade();
            break;
        default:
            break;
    }

    return;
}

void Micro::checkFootswitch() {

    // Poll the footswitch for new input
    int id = footSwitch.checkSwitches();

    // If a switch is pressed and is not the current state, handle it accordingly
    if ((id != SWITCH_NONE) && (id != mainSwitch)) {
        mainSwitch = id; // Set the main variable to the new switch
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

    return;
}