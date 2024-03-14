/*=====================================================================================*\
| Author:   Christopher Coyne                                         March 13th, 2024  |
| --------------------------------------------------------------------------------------|
| MODULE:     [ Micro ]                                                                 |
| --------------------------------------------------------------------------------------|
| DESCRIPTION:                                                                          |
|    Micro class                                                                        |
| --------------------------------------------------------------------------------------|
\*=====================================================================================*/

#ifndef MICRO_H
#define MICRO_H

/****************************************************
 *  Include files                                   *
 ****************************************************/
#include "Footswitch.h"
#include "LEDController.h"
#include "SerialCommunication.h"

/****************************************************
 *  Class definition                                *
 ****************************************************/

class Micro {
    private:
        Footswitch footSwitch;
        LEDController ledController;
        SerialCommunication serialCommunication;
        State mainState;
    public:
        Micro(int switchPins[4]);
        ~Micro();
        void microInit();
        void checkFootswitch();
        void mainFunction();
};

#endif // MICRO_H