//This is simple setup to get started with Particle Photon and IFTTT: 

//1) Upload the code to your #particle #photon 
//2) Create a Do recipe (from your smartphone) to call a function in this case called "ledToggle" with input "on" (Don't include quotes)
//3) Create this recipe, select the Event (as trigger) "BlinkLight" with data "On" 

int led1 = D0;
int led2 = D7; 

 
void setup() { 
   
    pinMode(led1, OUTPUT); 
    pinMode(led2, OUTPUT); 
    
    // We are also going to declare a Particle.function so that we can turn the LED on and off from the cloud. 
    
    Particle.function("LEDS",ledToggle); 
    // This is saying that when we ask the cloud for the function "led", it will employ the function ledToggle() from this app. e,make sure both LEDs are off when we start: 
   
    digitalWrite(led1, LOW); 
    digitalWrite(led2, LOW); 
    } 
    
    void loop() { 
        // Nothing to do here and no specific IFTTT based code
    } 
    
    
    // We're going to have a super cool function now that gets called when a matching API request is sent

   int ledToggle(String command) { 
        /* Spark.functions always take a string as an argument and return an integer. Since we can pass a string,
        it means that we can give the program commands on how the function should be used. In this case, telling the
        function "on" will turn the LED on and telling it "off" will turn the LED off. Then, the function
        returns a value to us to let us know what happened. In this case, it will return 1 for the LEDs turning on,
        0 for the LEDs turning off, and -1 if we received a totally bogus command that didn't do anything to the LEDs. */ 
        
        if (command=="on") { 
            digitalWrite(led1,HIGH);
            digitalWrite(led2,HIGH); 
            Particle.publish("BlinkLight", "On"); 
            delay(3000); 
            
                if (digitalRead(led2)){   //this reads the state of the pin and shuts both LEDS off if it reads high
                    
                digitalWrite(led1,LOW);
                digitalWrite(led2,LOW); 
                } 
                
                return 1; 
                }
                
        else if (command=="off") { 
                    digitalWrite(led1,LOW);
                    digitalWrite(led2,LOW); 
                    Particle.publish("BlinkLight", "Off"); 
                    return 0;
                    } 
                    
else { 
        return -1; 
    Particle.publish("BlinkLight", "Failed");
    } 
    }
