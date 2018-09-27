//This code uses the potentiometer to change the brightness of an LED. A discreet LED will need to be connected
    //from pin 3 to ground
    
    
int led = D3; // Instead of writing D7 over and over again, we'll write led2
// This one is the little blue LED on your board. On the Photon it is next to D7, and on the Core it is next to the USB jack.

// Define a pin that we'll place the pot on..This is one of the analog pins
int potPin = A0;

// Create a variable to hold the pot reading
int potReading = 0;


// Create a variable to store the LED brightness.
int ledBrightness = 0;


//int buttonState = 0;         // variable for reading the pushbutton status

void setup() {

  pinMode(led, OUTPUT);         //define LED pin as an output

}

void loop() {
    
    
  // Use analogRead to read the potentiometer reading
  // This gives us a value from 0 to 4095
  potReading = analogRead(potPin);

  // Map this value into the PWM range (0-255)
  // and store as the led brightness
  ledBrightness = map(potReading, 0, 4095, 0, 255);

  // fade the LED to the desired brightness
  analogWrite(led, ledBrightness);

  // wait 1/10th of a second and then loop
  delay(100);
  
}
