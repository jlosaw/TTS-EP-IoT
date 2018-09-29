//Measure the temp with the kit thermistor


#include "application.h"
#include <math.h>

// hookup the temp sensor to A4
#define TEMPPIN A4

// This routine runs only once upon reset
void setup()
{
  Serial.begin(9600);                           // init serial port on USB interface
}

// This routine loops forever
void loop()
{
  int B = 3975;                                                   // B value of the thermistor (inherent characteristic of sensor)

  int analogValue = analogRead(TEMPPIN);                          // read analog output from thermisor
  float resistance=(float)(4095-analogValue)*10000/analogValue;   //get the resistance of the sensor
  float temperature=1/(log(resistance/10000)/B+1/298.15)-273.15;  //convert to temperature via datasheet
  Serial.print("analogValue: ");
  Serial.println(analogValue);
  Serial.print("resistance: ");
  Serial.println(resistance);
  Serial.print("temperature: ");
  Serial.println(temperature);
  Serial.println("");
  
  delay(200);
}
