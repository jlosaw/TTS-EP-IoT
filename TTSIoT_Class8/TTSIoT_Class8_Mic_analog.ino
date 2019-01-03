// name the pins
#define MICPIN A0

// This routine runs only once upon reset
void setup()
{
  Serial.begin(9600);
}

// This routine loops forever
void loop()
{
 int analogValue = analogRead(MICPIN);       // read light sensor pin
 Serial.print("Mic Analog Value: ");
 Serial.println(analogValue);
 Particle.publish("Ana",String (analogValue),60,PRIVATE);
// Particle.variable("analogvalue", String(analogValue), INT);
 
 delay(500);
}
