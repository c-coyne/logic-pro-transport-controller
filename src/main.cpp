#include <Arduino.h>
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
  delay(3000); // power-up safety delay
  Serial.begin(9600);
  Serial.println("Program is running...");
}

/****************************************************
 *  Main                                            *
 ****************************************************/
void loop() {
  micro.checkFootswitch();
  delay(2000);
}