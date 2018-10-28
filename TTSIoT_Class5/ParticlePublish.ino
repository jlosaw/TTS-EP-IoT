

// -----------------------------------------
// Analog Value to Particle Variable
// -----------------------------------------
/* In this example, we're going to build on the particle variable example and add a continiually 
updating state based on an analog reading. This will be pushed to the Particle console via 
a simple command called particle publish.
We will start with the rotary pot, but then we can try the light sensor on the same pin.
*/

int led=D7;         //define LED pin
int pot = A0;       // This is where your potentiometer or photoresistor is plugged in.
int analogvalue;    // Here we are declaring the integer variable analogvalue, which we will use later to store the value of the photoresistor.
int anaThreshold;   // This is a value halfway between ledOnValue and ledOffValue, above which we will assume the led is on and below which we will assume it is off.


void setup() {

    pinMode(pot,INPUT);  // Our photoresistor pin is input (reading the photoresistor)
    pinMode (led, OUTPUT);
    
    // We are going to declare a Particle.variable() here so that we can access the value of the photoresistor from the cloud.
    Particle.variable("analogvalue", &analogvalue, INT);
    // This is saying that when we ask the cloud for "analogvalue", this will reference the variable analogvalue in this app, which is an integer variable.
    anaThreshold=1500;
    // set analog threshhold to a mid range value. Adjust this to move the trigger threshold
}


void loop() {

    // read the analog pin
    analogvalue = analogRead(pot);
    
    Particle.publish("Analog Raw",String (analogvalue),PUBLIC);
    //send the raw value from the sensor to Particle console
    
  if (analogvalue>anaThreshold) {

    /* If you are above the threshold, we'll assume this creates a "HIGH"
    state. Else it results in a "LOW" state.
    */

        // Send a publish to your devices...
        Particle.publish("Analog Value","HIGH",60,PRIVATE);
        /*First argument is name of the variable, second is the value, third is "Time to live" (TTL), 
        fourth is public or private. Note that for public events, you need not define the TTL time
        (it will default to 60). However, private publish events require all 4 arguments
        */
        
        // And trigger the LED to give us a visual too
        digitalWrite(led,HIGH);
        
       
    }
    else {
        // Send a publish...
        Particle.publish("Analog Value","LOW",60,PRIVATE);
        // And turn the LED off to visualize the state
        digitalWrite(led,LOW);
     
    }
    
    delay (1000);
  }
