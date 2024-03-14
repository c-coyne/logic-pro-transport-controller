/*=====================================================================================*\
| Author:   Christopher Coyne                                         March 13th, 2024  |
| --------------------------------------------------------------------------------------|
| MODULE:     [ Micro ]                                                                 |
| --------------------------------------------------------------------------------------|
| DESCRIPTION:                                                                          |
|    Micro class                                                                        |
| --------------------------------------------------------------------------------------|
\*=====================================================================================*/

/****************************************************
 *  Include files                                   *
 ****************************************************/
#include "Micro.h"
#include <Arduino.h>
#include <Keyboard.h>

/****************************************************
 *  Constructor / destructor                        *
 ****************************************************/

Micro::Micro(int switchPins[4]) : footSwitch(switchPins) { mainState = State::STATE_INIT; }

Micro::~Micro() {}

/****************************************************
 *  Member functions                                *
 ****************************************************/

void Micro::microInit() {

    mainState = STATE_INIT; // Initialize state machine
    ledController.LEDControllerInit(); // Initialize LEDController object

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
            ledController.mainBrightness = BRIGHTNESS; // [FR_007]
            break;
        case STATE_FASTFORWARD:
            ledController.mainBrightness = BRIGHTNESS;
            break;
        case STATE_PLAY:
            ledController.internalFade(); // [FR_014]
            break;
        case STATE_STOP:
            ledController.mainBrightness = BRIGHTNESS;
            break;
        case STATE_RECORD:
            ledController.internalFade(); // [FR_018]
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

        switch(id) {

            case SWITCH_0: // REWIND
                switch (mainState) {
                    case STATE_INIT:
                    case STATE_REWIND:
                    case STATE_FASTFORWARD:
                    case STATE_STOP:
                        mainState = STATE_REWIND;
                        serialCommunication.sendCommand(id);
                        ledController.setLEDColor(REWIND_COLOR); // [FR_002]
                        ledController.fade(300, 1, false, true); // [FR_003]
                        break;
                    case STATE_START:
                        break;
                    case STATE_PLAY:
                    case STATE_RECORD:
                        serialCommunication.sendCommand(id); // [FR_004]
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
                        serialCommunication.sendCommand(id);    // [FR_005]
                        ledController.setLEDColor(START_COLOR); // [FR_006, FR_007]
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
                        serialCommunication.sendCommand(id); // [FR_011]
                        ledController.setLEDColor(FASTFORWARD_COLOR); // [FR_009]
                        ledController.fade(300, 1, false, true); // [FR_010]
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
                        serialCommunication.sendCommand(id); // [FR_015]
                        ledController.setLEDColor(PLAY_COLOR); // [FR_013]
                        break;
                    case STATE_PLAY:
                    case STATE_RECORD:
                        mainState = STATE_STOP;
                        serialCommunication.sendCommand(id);
                        ledController.setLEDColor(STOP_COLOR); // [FR_013]
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
                        ledController.setLEDColor(RECORD_COLOR); // [FR_017]
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
