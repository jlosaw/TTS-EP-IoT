
// -----------------------------------
// Controlling LEDs over the Internet
// -----------------------------------

int buzz = D2;
int led = D7;

void setup()
{

   // Here's the pin configuration
   pinMode(buzz, OUTPUT);
   pinMode(led, OUTPUT);

   // We are also going to declare a Particle.function so that we can turn the LED ond buzzer on and off from the cloud.
   Particle.function("led",ledToggle);
   
   // This is saying that when we ask the cloud for the function "led", it will employ the function ledToggle() from this app.

   // For good measure, let's also make sure both LEDs are off when we start:
   digitalWrite(buzz, LOW);
   digitalWrite(led, LOW);

}


/* Last time, we wanted to continously blink the LED on and off
Since we're waiting for input through the cloud this time,
we don't actually need to put anything in the loop */

void loop()
{
   // Nothing to do here
}

// We're going to have a super cool function now that gets called when a matching API request is sent
// This is the ledToggle function we registered to the "led" Particle.function earlier.

int ledToggle(String command) {
    /* Particle.functions always take a string as an argument and return an integer.
    Since we can pass a string, it means that we can give the program commands on how the function should be used.
    In this case, telling the function "on" will turn the LED on and telling it "off" will turn the LED off.
    Then, the function returns a value to us to let us know what happened.
    In this case, it will return 1 for the LEDs turning on, 0 for the LEDs turning off,
    and -1 if we received a totally bogus command that didn't do anything to the LEDs.
    */

    if (command=="on") {
        digitalWrite(buzz,HIGH);
        digitalWrite(led,HIGH);
        return 1;
    }
    else if (command=="off") {
        digitalWrite(buzz,LOW);
        digitalWrite(led,LOW);
        return 0;
    }
    else {
        return -1;
    }
}
