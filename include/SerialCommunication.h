#ifndef SERIALCOMMUNICATION_H
#define SERIALCOMMUNICATION_H

#include <Keyboard.h>
#include <Arduino.h>
#include "Cfg_Types.h"

class SerialCommunication {
    private:
        
    public:
        SerialCommunication();
        ~SerialCommunication();
        void sendCommand(SwitchID id);
};

#endif // SERIALCOMMUNICATION_H