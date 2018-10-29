// -----------------------------------------
// Particle Subscribe
// -----------------------------------------
/* In this example, we will listen into the published events from the temperature read sketch and 
 sound the alarm if it gets too high or low
 */


int led=D7;             //define LED pin
int buzzer = D2;        //buzzer pin


void setup() {

    pinMode (led, OUTPUT);
    pinMode (buzzer, OUTPUT);
    
    Particle.subscribe("JLO_Temp", myHandler);
      
    // This is the event that we are subscribing too. It must correspond to the event name from temp sensor
}


void loop() {

  }


// Now for the myHandler function, which is called when the cloud tells us that our buddy's event is published.
void myHandler(const char *event, const char *data)
{
  /* Particle.subscribe handlers are void functions, which means they don't return anything.
  They take two variables-- the name of your event, and any data that goes along with your event.
  In this case, the event will be "JLO_temp" and the data will be "high" or "low"

  Since the input here is a char, we can't do
     data=="intact"
    or
     data=="broken"

  chars just don't play that way. Instead we're going to strcmp(), which compares two chars.
  If they are the same, strcmp will return 0.
  */

  if (strcmp(data,"high")==0) {
    // if temp is high, sound the alarm
    digitalWrite(buzzer,HIGH);
    digitalWrite(led,HIGH);
    delay (2000);
    digitalWrite(buzzer,LOW);
  }
  else if (strcmp(data,"low")==0) {
    // if temp is low, sound the alarm too
    digitalWrite(buzzer,HIGH);
    digitalWrite(led,HIGH);
    delay (2000);
    digitalWrite(buzzer,LOW);
  }
  
  else {
    digitalWrite(buzzer,LOW); 
    digitalWrite(led,LOW);
    
    
  }
}
