#include "application.h"

// name the pins
#define LIGHTPIN A0

// This routine runs only once upon reset
void setup()
{
  Serial.begin(9600);
}

// This routine loops forever
void loop()
{
 int analogValue = analogRead(LIGHTPIN);       // read light sensor pin
 Serial.print("light strength: ");
 Serial.println(analogValue);

 delay(500);
}
