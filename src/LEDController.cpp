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

void LEDController::internalFade() {

    // Keep track of whether the LEDs are fading up or down
    static bool increasing = false;

    // Change fade direction if necessary
    if (mainBrightness <= 1) { increasing = true; }
    else if (mainBrightness >= BRIGHTNESS) { increasing = false; }

    // Set brightness of LED string
    mainBrightness = (increasing) ? mainBrightness + mainInterval : mainBrightness - mainInterval;
    setBrightness(mainBrightness);

    return;
}

void LEDController::fade(int duration, int n, bool increasing, bool endBright) {

    // Set up interval and initial color component, initialize fade count
    float interval = float(BRIGHTNESS) / (duration / 2.);
    float brightness = (increasing) ? 0. : float(BRIGHTNESS);
    int count = 0;
    bool countLow = (increasing) ? true : false;

    // Gradually fade the LED up and down {n} times
    while (count < n) {

        setBrightness(brightness);

        if (increasing) {
            brightness += interval;
            if (brightness > BRIGHTNESS) {
                increasing = false;
                if (!countLow) {count++;}
                }
        } else {
            brightness -= interval;
            if (brightness <= 1) {
                increasing = true;
                if (countLow) {count++;}
                }
        }

        // Wait 1 ms between cycles
        delay(1);
    }

    // If the LED strip should end bright (vs. dark)
    if (endBright) {       

        while (brightness < BRIGHTNESS) {
            setBrightness(brightness);
            brightness += interval;
            delay(1);
        }

    }

    return;
}

void LEDController::LEDControllerInit() {

    // Initialize main variables
    mainBrightness = BRIGHTNESS;
    mainInterval = BRIGHTNESS / 500.;
    mainColor = CRGB::White;

    // Set initial LED brightness and color
    setBrightness(0);
    setLEDColor(mainColor);

    // Fade LED strip up and down two times as init sequence
    fade(300, 2, true, false);

    // Fade LEDs up to BRIGHTNESS to indicate device is ready
    float interval = float(BRIGHTNESS) / 2000.;
    float brightness = 0;
    for (int i=0; i<2001; i++) {
        setBrightness(brightness);
        brightness += interval;
        delay(1);
    }

    return;
}

void LEDController::setBrightness(int brightness) {
    FastLED.setBrightness(brightness);
    FastLED.show();

    return;
}

void LEDController::setLEDColor(CRGB color) {
    fill_solid( leds, NUM_LEDS, color);
    FastLED.show();

    return;
}