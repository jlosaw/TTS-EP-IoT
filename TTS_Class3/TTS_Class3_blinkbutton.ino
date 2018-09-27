int button = D2;     // Define the digital pin for the button


int led = D7;       // This one is the little blue LED on your board. On the Photon it is next to D7, and on the Core it is next to the USB jack.


int buttonState = 0;         // variable for reading the pushbutton status

void setup() {

  pinMode(button, INPUT);
  pinMode(led, OUTPUT);

}


void loop() {
    
buttonState = digitalRead(button);

if (buttonState==HIGH){
   digitalWrite(led, HIGH);
}
else{
     digitalWrite(led, LOW);
}
}

