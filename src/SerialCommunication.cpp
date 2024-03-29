/*=====================================================================================*\
| Author:   Christopher Coyne                                         March 13th, 2024  |
| --------------------------------------------------------------------------------------|
| MODULE:     [ SerialCommunication ]                                                   |
| --------------------------------------------------------------------------------------|
| DESCRIPTION:                                                                          |
|    SerialCommunication class                                                          |
| --------------------------------------------------------------------------------------|
\*=====================================================================================*/

/****************************************************
 *  Include files                                   *
 ****************************************************/
#include "SerialCommunication.h"

/****************************************************
 *  Constructor / destructor                        *
 ****************************************************/

SerialCommunication::SerialCommunication() {}

SerialCommunication::~SerialCommunication() {}

/****************************************************
 *  Member functions                                *
 ****************************************************/

void SerialCommunication::sendCommand(SwitchID id) {

#ifdef SERIAL_ENABLED
    
    switch(id) {
        case SWITCH_INIT:
            break;
        case SWITCH_0:
            Keyboard.press(REWIND_COMMAND);
            delay(10);
            Keyboard.releaseAll();
            break;
        case SWITCH_0_LONG:
            Keyboard.press(START_COMMAND);
            delay(10);
            Keyboard.releaseAll();
            break;
        case SWITCH_1:
            Keyboard.press(FASTFORWARD_COMMAND);
            delay(10);
            Keyboard.releaseAll();
            break;
        case SWITCH_2:
            Keyboard.press(PLAY_STOP_COMMAND);
            delay(10);
            Keyboard.releaseAll();
            break;
        case SWITCH_3:
            Keyboard.press(RECORD_COMMAND);
            delay(10);
            Keyboard.releaseAll();
            break;
        default:
            break;
    }

#endif // SERIAL_ENABLED

    return;
}