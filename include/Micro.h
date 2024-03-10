#ifndef MICRO_H
#define MICRO_H

#include "Footswitch.h"
#include "LEDController.h"
#include "SerialCommunication.h"

class Micro {
    private:
        Footswitch footSwitch;
        LEDController ledController;
        SerialCommunication serialCommunication;
        int mainSwitch;
        State mainState;
    public:
        Micro(int switchPins[4]);
        ~Micro();
        void microInit();
        void checkFootswitch();
        void mainFunction();
};

#endif // MICRO_H