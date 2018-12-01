// In this example, we will listen into the published events from Losant and 


int led=D7;             //define LED pin

void setup() {

    pinMode (led, OUTPUT);
  
    // We will setup an integration and a workflow inside Losant to push an "alarm" event to Particle. 
    // We subscribe to that event here.
    
   Particle.function("alarm", soundTheAlarm);
    
   }


void loop() {

  }

// Do a simple write to the onboard LED to let us know when the event has been triggered
int soundTheAlarm(String data) {
  
        digitalWrite(led,HIGH);
        delay (5000);
        digitalWrite(led,LOW);
        
}
