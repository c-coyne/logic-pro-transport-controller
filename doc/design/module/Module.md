# Module design

```mermaid
classDiagram
    Footswitch o-- Switch
    Micro --> Footswitch
    Micro --> LEDController
    class Switch{
        -int id
        -int pin
        +bool isPressed()
    }
    class Footswitch{
        -Switch switch1
        -Switch switch2
        -Switch switch3
        -Switch switch4
        +int checkSwitches()
    }
    class Micro{
        -Footswitch footswitch
        -LEDController ledController
        -int currentSwitch
        -State currentState
        -void fade(int duration, int count, bool increasing, bool endBright)
        +void microInit()
        +void checkFootswitch()
    }
    class LEDController{
        -CRGB leds[NUM_LEDS]
        +void setBrightness(int brightness)
        +void setLEDColor(CRGB color)
    }
```