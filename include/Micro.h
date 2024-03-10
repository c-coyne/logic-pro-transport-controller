#ifndef MICRO_H
#define MICRO_H

#include "Footswitch.h"
#include "LEDController.h"

class Micro {
    private:
        Footswitch footSwitch;
        LEDController ledController;
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