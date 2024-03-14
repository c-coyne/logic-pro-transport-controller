/*=====================================================================================*\
| Author:   Christopher Coyne                                         March 13th, 2024  |
| --------------------------------------------------------------------------------------|
| MODULE:     [ SerialCommunication ]                                                   |
| --------------------------------------------------------------------------------------|
| DESCRIPTION:                                                                          |
|    SerialCommunication class                                                          |
| --------------------------------------------------------------------------------------|
\*=====================================================================================*/

#ifndef SERIALCOMMUNICATION_H
#define SERIALCOMMUNICATION_H

/****************************************************
 *  Include files                                   *
 ****************************************************/
#include <Keyboard.h>
#include <Arduino.h>
#include "Cfg_Types.h"

/****************************************************
 *  Class definition                                *
 ****************************************************/

class SerialCommunication {
    public:
        SerialCommunication();
        ~SerialCommunication();
        void sendCommand(SwitchID id);
};

#endif // SERIALCOMMUNICATION_H