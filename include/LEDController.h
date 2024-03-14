/*=====================================================================================*\
| Author:   Christopher Coyne                                         March 13th, 2024  |
| --------------------------------------------------------------------------------------|
| MODULE:     [ LEDController ]                                                         |
| --------------------------------------------------------------------------------------|
| DESCRIPTION:                                                                          |
|    LEDController class                                                                |
| --------------------------------------------------------------------------------------|
\*=====================================================================================*/

#ifndef LEDCONTROLLER_H
#define LEDCONTROLLER_H

/****************************************************
 *  Include files                                   *
 ****************************************************/
#include <FastLED.h>
#include "Cfg_Types.h"

/****************************************************
 *  Class definition                                *
 ****************************************************/

class LEDController {
    private:
        CRGB leds[NUM_LEDS];
        float mainInterval;
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