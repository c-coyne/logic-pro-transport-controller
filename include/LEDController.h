#ifndef LEDCONTROLLER_H
#define LEDCONTROLLER_H

#include <FastLED.h>
#include "Cfg_Types.h"

class LEDController {
    private:
        CRGB leds[NUM_LEDS];
        float mainInterval;
        CRGB mainColor;
    public:
        float mainBrightness;
        LEDController();
        ~LEDController();
        void LEDControllerInit();
        void setBrightness(int brightness);
        void setLEDColor(CRGB color);
        void fade(int duration, int count, bool increasing, bool endBright);
        void internalFade();
};

#endif // LEDCONTROLLER_H