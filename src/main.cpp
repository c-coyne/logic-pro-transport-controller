#include <Arduino.h>
#include "Micro.h"

int switchPins[] = {2, 3, 4, 5};
Micro micro(switchPins);

void setup() {
  Serial.begin(9600);
  Serial.println("Program is running...");
}

void loop() {
  micro.checkFootswitch();
  delay(2000);
}