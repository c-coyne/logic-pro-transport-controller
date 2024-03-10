#ifndef MICRO_H
#define MICRO_H

#include "Footswitch.h"
#include "LEDController.h"

class Micro {
    private:
        Footswitch footSwitch;
        LEDController ledController;
        int mainSwitch;
        float mainBrightness;
        float mainInterval;
        State mainState;
        CRGB mainColor;
        void fade(int duration, int count, bool increasing, bool endBright);
        void internalFade();
    public:
        Micro(int switchPins[4]);
        ~Micro();
        void microInit();
        void checkFootswitch();
        void mainFunction();
};

#endif // MICRO_H