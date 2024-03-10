#ifndef FOOTSWITCH_H
#define FOOTSWITCH_H

#include "Switch.h"
#include "Cfg_Types.h"

class Footswitch {
    private:
        Switch switch1;
        Switch switch2;
        Switch switch3;
        Switch switch4;
    public:
        Footswitch(int switchPins[4]);
        ~Footswitch();
        SwitchID checkSwitches();
};

#endif // FOOTSWITCH_H