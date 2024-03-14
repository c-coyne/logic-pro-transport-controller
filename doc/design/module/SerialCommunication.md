# SerialCommunication Class

## Class Description

The SerialCommunication class represents the serial communication between the microcontroller and the connected laptop via USB. All emulated keyboard strokes are sent via the SerialCommunication class.

## Attributes

None.

## Methods

### `void sendCommand(SwitchID id)`
- **Description**: This method receives a switch ID and sends the appropriate message to the connected laptop via USB. Each message - configured in Cfg_Types.h - is an emulation of keyboard presses enabled by the Arduino keyboard library. Note that all serial communication can be turned on or off via the `SERIAL_ENABLED` macro in Cfg_Types.h
- **Input Parameters**: 
    - `SwitchID id`: the switch ID is used to determine which message to send.
- **Return Type**: Does not return a value.

## Dependencies

This class does not have any dependencies on other classes.

## Examples
```
// create a new SerialCommunication object
SerialCommunication sc();

// send a message
SwitchID switchId = SWITCH_1;
sc.sendCommand(switchId);
```