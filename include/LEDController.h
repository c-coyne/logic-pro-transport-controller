#ifndef LEDCONTROLLER_H
#define LEDCONTROLLER_H

#include <FastLED.h>
#include "Cfg_Types.h"

class LEDController {
    private:
        CRGB leds[NUM_LEDS];
    public:
        LEDController();
        ~LEDController();
        void setBrightness(int brightness);
        void setLEDColor(CRGB color);
};

#endif // LEDCONTROLLER_H