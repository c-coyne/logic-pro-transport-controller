/****************************************************
 *  Include files                                   *
 ****************************************************/
#include "LEDController.h"

LEDController::LEDController() {
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(BRIGHTNESS);
}

LEDController::~LEDController() {
    // deallocate resources if any
}

void LEDController::setBrightness(int brightness) {
    FastLED.setBrightness(brightness);
}

void LEDController::setLEDColor(CRGB color) {
    fill_solid( leds, NUM_LEDS, color);
    FastLED.show();
}