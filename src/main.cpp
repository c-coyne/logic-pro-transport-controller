#include <Arduino.h>
#include <Keyboard.h>
#include "Micro.h"
#include "Cfg_Types.h"

/****************************************************
 *  Local variables                                 *
 ****************************************************/
int switchPins[] = {SWITCH0_PIN, SWITCH1_PIN, SWITCH2_PIN, SWITCH3_PIN};
Micro micro(switchPins);

/****************************************************
 *  Setup                                           *
 ****************************************************/
void setup() {
  delay(3000); // Power-up safety delay
  micro.microInit(); // Initialize the microcontroller
}

/****************************************************
 *  Main                                            *
 ****************************************************/
void loop() {
  micro.checkFootswitch();
  micro.mainFunction();
  delay(1);
}