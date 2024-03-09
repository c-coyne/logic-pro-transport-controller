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
        void fade(int duration, int times);
    public:
        Micro(int switchPins[4]);
        ~Micro();
        void microInit();
        void checkFootswitch();
};

#endif // MICRO_H