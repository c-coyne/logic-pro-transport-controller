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
        case STATE_REWIND:
            ledController.mainBrightness = BRIGHTNESS;
            break;
        case STATE_START:
            ledController.mainBrightness = BRIGHTNESS;
            break;
        case STATE_FASTFORWARD:
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
    SwitchID id = footSwitch.checkSwitches();

    // If a switch is pressed and is not the current state, handle it accordingly
    if (id != SWITCH_NONE) {
        mainSwitch = id; // Set the main variable to the new switch
        switch(mainSwitch) {

            case SWITCH_0: // REWIND
                switch (mainState) {
                    case STATE_INIT:
                    case STATE_REWIND:
                    case STATE_FASTFORWARD:
                    case STATE_STOP:
                        mainState = STATE_REWIND;
                        serialCommunication.sendCommand(id);
                        ledController.setLEDColor(REWIND_COLOR);
                        ledController.fade(300, 1, false, true);
                        break;
                    case STATE_START:
                        break;
                    case STATE_PLAY:
                    case STATE_RECORD:
                        serialCommunication.sendCommand(id);
                        break;
                    default:
                        break;   
                }
                break;

            case SWITCH_0_LONG: // START
                switch (mainState) {
                    case STATE_INIT:
                    case STATE_REWIND:
                    case STATE_FASTFORWARD:
                    case STATE_STOP:
                        mainState = STATE_START;
                        serialCommunication.sendCommand(id);
                        ledController.setLEDColor(START_COLOR);
                        break;
                    case STATE_START:
                        break;
                    case STATE_PLAY:
                    case STATE_RECORD:
                        break;
                    default:
                        break;
                }
                break;

            case SWITCH_1: // FAST FORWARD
                switch (mainState) {
                    case STATE_INIT:
                    case STATE_REWIND:
                    case STATE_FASTFORWARD:
                    case STATE_STOP:
                    case STATE_START:
                        mainState = STATE_FASTFORWARD;
                        serialCommunication.sendCommand(id);
                        ledController.setLEDColor(FASTFORWARD_COLOR);
                        ledController.fade(300, 1, false, true);
                        break;
                    case STATE_PLAY:
                    case STATE_RECORD:
                        serialCommunication.sendCommand(id);
                        break;
                    default:
                        break;
                }
                break;

            case SWITCH_2: // PLAY / STOP
                switch (mainState) {
                    case STATE_INIT:
                    case STATE_REWIND:
                    case STATE_FASTFORWARD:
                    case STATE_STOP:
                    case STATE_START:
                        mainState = STATE_PLAY;
                        serialCommunication.sendCommand(id);
                        ledController.setLEDColor(PLAY_COLOR);
                        break;
                    case STATE_PLAY:
                    case STATE_RECORD:
                        mainState = STATE_STOP;
                        serialCommunication.sendCommand(id);
                        ledController.setLEDColor(STOP_COLOR);
                        break;
                    default:
                        break;
                }
                break;

            case SWITCH_3: // RECORD
                switch (mainState) {
                    case STATE_INIT:
                    case STATE_REWIND:
                    case STATE_FASTFORWARD:
                    case STATE_STOP:
                    case STATE_START:
                    case STATE_PLAY:
                        mainState = STATE_RECORD;
                        serialCommunication.sendCommand(id);
                        ledController.setLEDColor(RECORD_COLOR);
                        break;
                    case STATE_RECORD:
                    default:
                        break;
                }
                break;
            
            default:
                break;
        }

        ledController.setBrightness(BRIGHTNESS); // Regardless of state, set the brightness to BRIGHTNESS

    }

    return;
}
