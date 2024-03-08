#include <Arduino.h>
#include "Micro.h"

/****************************************************
 *  Local variables                                 *
 ****************************************************/
int switchPins[] = {2, 3, 4, 5};
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