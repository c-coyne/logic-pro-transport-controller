# LEDController Class

## Class Description

The LEDController class represents a physical string of LEDs, where each SMD 5050 LED has an integrated driver IC that allows for independent control of color and brightness. This class uses the FastLED library to facilitate control of the LED string.

## Attributes

- `CRGB leds[NUM_LEDS]`: array of CRGB structs representing the LED string of size `NUM_LEDS`
- `float mainInterval`: the `mainInterval` is used to control the cycle time of the LED pulse detailed in `LEDController::internalFade()`
- `float mainBrightness`: the `mainBrightness` is used to keep track of the underbody LED brightness in between calls to `LEDController::internalFade()`

## Methods

### `LEDController()`
- **Description**: This is the constructor for the `LEDController` class. It initializes a new instance of an `LEDController`.
- **Input Parameters**: None.
- **Return Type**: Does not return a value.

### `~LEDController()`
- **Description**: This is the destructor for the `LEDController` class. It cleans up the instance of the `LEDController` when it's no longer needed.
- **Input Parameters**: None.
- **Return Type**: Does not return a value.

### `void LEDControllerInit()`
- **Description**: Initializes the LEDController object.
- **Input Parameters**: None.
- **Return Type**: Does not return a value.

### `void setBrightness(int brightness)`
- **Description**: Sets the brightness of the LED string.
- **Input Parameters**:
    - `int brightness`: Value from 0 (darkest) to 255 (brightest)
- **Return Type**: Does not return a value.

### `void setLEDColor(CRGB color)`
- **Description**: Sets the color of the LED string.
- **Input Parameters**:
    - `CRGB color`: color to which the LED string should be set. All 168 pre-defined colors are detailed in _pixeltypes.h_, but custom colors can be developed as well.
.- **Return Type**: Does not return a value.

### `void fade(int duration, int count, bool increasing, bool endBright)`
- **Description**: Fades the LED string from light to dark to light (`increasing = false`) or from dark to light to dark (`increasing = true`) a total of `count` times. If `endBright` is true, the LED string will fade back up to `BRIGHTNESS` after `count` fade cycles.
- **Input Parameters**:
    - `int duration`: cycle time for the full fade (bright to dark to bright or dark to bright to dark) in seconds
    - `int count`: number of fade cycles to execute
    - `bool increasing`: variable to determine if the cycles should start dark (`increasing = true`) or bright (`increasing = false`)
    - `bool endBright`: determines if the fade cycle should end bright or not. This is only meaningful if `increasing == false`
- **Return Type**: Does not return a value.

### `void internalFade()`
- **Description**: This function is used to gradually fade the LED string up and down "in the background", i.e. while no switches are pressed. This is used in the states `STATE_PLAY` and `STATE_RECORD`.
- **Input Parameters**: None
- **Return Type**: Does not return a value.

## Dependencies

This class does not have any dependencies on other classes.

## Examples
```
// create a new LEDController object
LEDController ledController();

// set brightness of LED string
ledController.setBrightness(255);

// set color of LED string
ledController.setColor(CRGB::White);
```