#ifndef FOOTSWITCH_H
#define FOOTSWITCH_H

#include "Switch.h"

class Footswitch {
    private:
        Switch switch1;
        Switch switch2;
        Switch switch3;
        Switch switch4;
    public:
        Footswitch(int switchPins[4]);
        ~Footswitch();
        int checkSwitches();
};

#endif // FOOTSWITCH_H