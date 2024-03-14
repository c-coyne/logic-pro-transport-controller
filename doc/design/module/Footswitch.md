# Footswitch Class

## Class Description

The `Footswitch` class represents a physical [Fender 4-button footswitch for the Mustang series guitar amplifiers](https://www.fender.com/en-US/parts/footswitches/4-button-footswitch-mustang-series-amplifiers/0080996000.html). It's comprised for four [Switch](Switch.md) objects representing the four pushbutton switches.

## Attributes

- `switch0`: The first pushbutton switch on the footswitch.
- `switch1`: The second pushbutton switch on the footswitch.
- `switch2`: The third pushbutton switch on the footswitch.
- `switch3`: The fourth pushbutton switch on the footswitch.

## Methods

### `Footswitch(int switchPins[4])`
- **Description**: This is the constructor for the `Footswitch` class. It initializes a new instance of a `Switch`, which sets up four `Switch` objects per below. Each of the four switch pins are then configured with an internal pull-up resistor so that the default state is `HIGH`.
The switch objects are:
    - `switch0(0, switchPins[0])` --> id = 0, pin = switchPins[0]
    - `switch1(1, switchPins[1])` --> id = 1, pin = switchPins[1]
    - `switch2(2, switchPins[2])` --> id = 2, pin = switchPins[2]
    - `switch3(3, switchPins[3])` --> id = 3, pin = switchPins[3]
- **Input Parameters**: 
    - `int switchPins[4]`: an array of integers defining which pin each switch is connected to (switch0 = element 0, switch1 = element 1, etc.).
- **Return Type**: Does not return a value.

### `~Footswitch()`
- **Description**: This is the destructor for the `Footswitch` class. It cleans up the instance of the `Footswitch` when it's no longer needed.
- **Input Parameters**: None.
- **Return Type**: Does not return a value.

### `SwitchID checkSwitches()`
- **Description**: This method reads the state of each of the switches on the footswitch. If a switch is pressed, this method returns the corresponding switch ID. If no switch is pressed, it returns `SWITCH_NONE`. Note that `switch0` has different functionality depending on its press duration: if it's pressed <1 second, it sends a `SWITCH_0` reponse; otherwise, if it's pressed >=1 second, it sends a `SWITCH_0_LONG` response. Also note that there is an inherent priority built into the method: `switch0` > `switch1` > `switch2` > `switch3`.
- **Input Parameters**: None.
- **Return Type**: Returns the `SwitchID` of the switch that is pressed, otherwise `SWITCH_NONE`.

## Dependencies

This class has a dependency on the [Switch](Switch.md) class.

## Examples
```
// create a new footswitch object
int switchPins[4] = { 5, 6, 7, 8 };
FootSwitch fs(switchPins);

// check the state of the footswitch
SwitchID switchId = fs.checkSwitches();

// take action according to which switch is pressed
switch(switchId) {
    case SWITCH_0:
        // execute when switch0 is pressed (short press)
    case SWITCH_0_LONG:
        // execute when switch0 is pressed (long press)
    case SWITCH_1:
        // execute when switch1 is pressed
    case SWITCH_2:
        // execute when switch2 is pressed
    case SWITCH_3:
        // execute when switch3 is pressed
    default:
        // default case
}
```