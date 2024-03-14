# Micro Class

## Class Description

The Micro class represents the microcontroller (in this project, Arduino Micro board based on the ATmega32U4).

## Attributes

- `Footswitch footSwitch`: the [Footswitch](Footswitch.md) member variable, representing the Fender footswitch
- `LEDController ledController`: the [LEDController](LEDController.md) member variable, representing the LED string
- `SerialCommunication serialCommunication`: the [SerialCommunication](SerialCommunication.md) member variable, enabling USB communication with the connected laptop
- `State mainState`: this variable is used to keep track of the current state in the state machine

## Methods

### `void microInit()`
- **Description**: Initializes the microcontroller state machine to `STATE_INIT` and initializes the `LEDController ledController` member variable.
- **Input Parameters**: None.
- **Return Type**: Does not return a value.

### `void checkFootswitch()`
- **Description**: This method polls the footswitch for new input, then acts on it accordingly. If no switches are pressed, there is no action to be taken. If a switch is pressed, then the `mainState` is assessed to determine the necessary action to take. This typically involves setting the LED string to a specified color and sending a command to the connected laptop.
- **Input Parameters**: None.
- **Return Type**: Does not return a value.

### `void mainFunction()`
- **Description**: This function checks the current state in the state machine via `mainState` and executes accordingly. In this project, this is only used to pulsate the LED string when in the `STATE_PLAY` and `STATE_RECORD` states.
- **Input Parameters**: None.
- **Return Type**: Does not return a value.

## Dependencies

This class requires the [Footswitch](Footswitch.md), [LEDController](LEDController.md), and [SerialCommunication](SerialCommunication.md) classes.

## Examples
```
// create a new micro object
int switchPins[] = { 5, 6, 7, 8 };
Micro micro(switchPins);

// poll for input from the footswitch
micro.checkFootswitch();

// execute actions per the state machine
micro.mainFunction();
```