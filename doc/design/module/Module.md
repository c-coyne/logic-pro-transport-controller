# Module design

```mermaid
classDiagram
    Footswitch o-- Switch
    Micro --> Footswitch
    Micro --> LEDController
    Micro --> SerialCommunication
    class Switch{
        -int id
        -int pin
        +bool isPressed()
    }
    class Footswitch{
        -Switch switch0
        -Switch switch1
        -Switch switch2
        -Switch switch3
        +SwitchID checkSwitches()
    }
    class Micro{
        -Footswitch footswitch
        -LEDController ledController
        -SerialCommunication serialCommunication;
        -State mainState
        +void microInit()
        +void checkFootswitch()
        +void mainFunction()
    }
    class LEDController{
        -CRGB leds[NUM_LEDS]
        -float mainInterval
        +float mainBrightness
        +void LEDControllerInit()
        +void setBrightness(int brightness)
        +void setLEDColor(CRGB color)
        +void fade(int duration, int count, bool increasing, bool endBright)
        +void internalFade()
    }
    class SerialCommunication{
        +void sendCommand(SwitchID id)
    }
```