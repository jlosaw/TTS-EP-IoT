int led = D7;

void setup(){
    pinMode(led, OUTPUT);
   
    //We "Subscribe" to our IFTTT event called Button so that we get events for it 
    Particle.subscribe("TTSLED", myHandler);
    
}



void loop() {
    //nothing to do in the loop
}


//The function that handles the event from IFTTT
void myHandler(const char *event, const char *data){
   
    digitalWrite(led, HIGH);
    delay(5000);
    digitalWrite(led, LOW);
    
    //you can do anything you want here once you get the trigger from IFTTT
}
