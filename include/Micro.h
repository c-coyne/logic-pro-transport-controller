#ifndef MICRO_H
#define MICRO_H

#include "Footswitch.h"
#include "LEDController.h"

class Micro {
    private:
        Footswitch footSwitch;
        LEDController ledController;
        int currentSwitch;
        State currentState;
    public:
        Micro(int switchPins[4]);
        ~Micro();
        void checkFootswitch();
};

#endif // MICRO_H