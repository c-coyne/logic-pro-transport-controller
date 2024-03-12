# Project Requirements

## Functional Requirements
* **FR_001**: When Button 1 on the Fender footswitch is pressed, the system shall detect the button press within 10 ms.
* **FR_002**: When the Button 1 button press is detected by the system, the underbody LEDs shall emit Indigo light.
* **FR_003**: When the Button 1 button press is detected by the system, the underbody LEDs shall blink once with gradual fade off and back on, with total cycle time of 0.5 seconds.
* **FR_004**: When the Button 1 button press is detected by the system, the system shall generate a keyboard shortcut "," (Logic Pro X: Rewind).
* **FR_005**: When Button 1 is held down for more than 1 second, the system shall generate a keyboard shortcut "Return" (Logic Pro X: Go To Beginning).
* **FR_006**: When Button 1 is held down for more than 1 second, the system shall turn the underbody LEDs off and gradually fade up to the original brightness, with total cycle time of 2 seconds.
* **FR_007**: When Button 2 on the Fender footswitch is pressed, the system shall detect the button press within 10 ms.
* **FR_008**: When the Button 2 button press is detected by the system, the underbody LEDs shall emit Indigo light.
* **FR_009**: When the Button 2 button press is detected by the system, the underbody LEDs shall blink once with gradual fade off and back on, with total cycle time of 0.5 seconds.
* **FR_010**: When the Button 2 button press is detected by the system, the system shall generate a keyboard shortcut "." (Logic Pro X: Forward).
* **FR_011**: When Button 3 on the Fender footswitch is pressed, the system shall detect the button press within 10 ms.
* **FR_012**: When the Button 3 button press is detected by the system, the underbody LEDs shall emit Green light when playing and Orange light when stopping.
* **FR_013**: When the Button 3 button press is detected by the system, the system shall generate a keyboard shortcut "Space bar" (Logic Pro X: Play / Stop).
* **FR_014**: When Button 4 on the Fender footswitch is pressed, the system shall detect the button press within 10 ms.
* **FR_015**: When the Button 4 button press is detected by the system, the underbody LEDs shall emit Red light.
* **FR_016**: When the Button 4 button press is detected by the system, the underbody LEDs shall pulsate at 0.2-1.0 Hz.
* **FR_017**: When the Button 4 button press is detected by the system, the system shall generate a keyboard shortcut "r" (Logic Pro X: Record).

## Non-Functional Requirements
* **NFR_001**: The system shall be operational with only one cable connecting the Fender footswitch to the laptop.
* **NFR_002**: The system shall be reprogrammable via the single cable connecting the Fender footswitch to the laptop.
* **NFR_003**: After connecting the Fender footswitch to the laptop using the designated cable, the system shall start running without requiring additional configuration.
* **NFR_004**: The project shall send the shortcut commands for a Macbook Pro laptop.