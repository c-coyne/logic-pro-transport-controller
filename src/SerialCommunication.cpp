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

    #ifdef SERIAL_ENABLED
    
    switch(id) {
        case SWITCH_INIT:
            break;
        case SWITCH_0:
            // Keyboard.press(REWIND_COMMAND);
            Keyboard.press(48);
            delay(10);
            Keyboard.releaseAll();
            break;
        case SWITCH_0_LONG:
            // Keyboard.press(START_COMMAND);
            Keyboard.press(49);
            delay(10);
            Keyboard.releaseAll();
            break;
        case SWITCH_1:
            // Keyboard.press(FASTFORWARD_COMMAND);
            Keyboard.press(50);
            delay(10);
            Keyboard.releaseAll();
            break;
        case SWITCH_2:
            // Keyboard.press(PLAY_STOP_COMMAND);
            Keyboard.press(51);
            delay(10);
            Keyboard.releaseAll();
            break;
        case SWITCH_3:
            // Keyboard.press(RECORD_COMMAND);
            Keyboard.press(52);
            delay(10);
            Keyboard.releaseAll();
            break;
        default:
            break;
    }

    #endif // SERIAL_ENABLED

    return;
}