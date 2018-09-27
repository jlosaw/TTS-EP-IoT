//TTSEP IoT Class 4
//Plug buzzer into D2 on the dev board

// name the pins
#define BUZZERPIN D2

// This routine runs only once upon reset
void setup()
{
  pinMode(BUZZERPIN, OUTPUT);                         // set user key pin as input

}
// This routine loops forever


void loop()
{
    tone(BUZZERPIN, 1000); // Send 1KHz sound signal...
    delay(500);
    noTone(BUZZERPIN);     // Stop sound...
    delay(1000);

}
