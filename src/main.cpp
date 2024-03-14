/****************************************************
 *  Include files                                   *
 ****************************************************/
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

  micro.microInit(); // Initialize the microcontroller

}

/****************************************************
 *  Main                                            *
 ****************************************************/

void loop() {

  micro.checkFootswitch(); // [FR_001, FR_008, FR_012, FR_016]
  micro.mainFunction();
  delay(1);

}