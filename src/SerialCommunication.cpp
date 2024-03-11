/****************************************************
 *  Include files                                   *
 ****************************************************/
#include "SerialCommunication.h"

SerialCommunication::SerialCommunication() {
    // additional initialization if required
}

SerialCommunication::~SerialCommunication() {
    // deallocate resources if any
}

void SerialCommunication::sendCommand(SwitchID id) {
    if (SERIAL_ENABLED) {
        switch(id) {
            case SWITCH_INIT:
                break;
            case SWITCH_0:
                if (SWITCH0_MACCMD) { Keyboard.press(KEY_LEFT_GUI); }
                Keyboard.press(SWITCH0_COMMAND);
                Keyboard.release(SWITCH0_COMMAND);
                delay(10);
                Keyboard.releaseAll();
                break;
            case SWITCH_1:
                if (SWITCH1_MACCMD) { Keyboard.press(KEY_LEFT_GUI); }
                Keyboard.press(SWITCH1_COMMAND);
                Keyboard.release(SWITCH1_COMMAND);
                delay(10);
                Keyboard.releaseAll();
                break;
            case SWITCH_2:
                if (SWITCH2_MACCMD) { Keyboard.press(KEY_LEFT_GUI); }
                Keyboard.press(SWITCH2_COMMAND);
                Keyboard.release(SWITCH2_COMMAND);
                delay(10);
                delay(10);
                Keyboard.releaseAll();
                break;
            case SWITCH_3:
                if (SWITCH3_MACCMD) { Keyboard.press(KEY_LEFT_GUI); }
                Keyboard.press(SWITCH3_COMMAND);
                Keyboard.release(SWITCH3_COMMAND);
                delay(10);
                Keyboard.releaseAll();
                break;
            default:
                break;
        }
    } // if SERIAL_COMS == true
    
    return;
}