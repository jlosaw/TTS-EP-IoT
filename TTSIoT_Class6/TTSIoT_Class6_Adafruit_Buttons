// This #include statement was automatically added by the Particle IDE.
#include "lib1.h"

// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_MQTT.h>



// This #include statement was automatically added by the Particle IDE. 
#include "Adafruit_MQTT/Adafruit_MQTT.h" 
#include "Adafruit_MQTT/Adafruit_MQTT_SPARK.h" 
#include "Adafruit_MQTT/Adafruit_MQTT.h" 
/************************* Adafruit.io Setup *********************************/ 
#define AIO_SERVER      "io.adafruit.com" 
#define AIO_SERVERPORT  1883                   // use 8883 for SSL 
#define AIO_USERNAME    "jlosaw" 
#define AIO_KEY         "b17cf7bc482443fe9217a082ad445b80" 


/************ Global State (you don't need to change this!) ***   ***************/ 
TCPClient TheClient; 

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details. 
Adafruit_MQTT_SPARK mqtt(&TheClient,AIO_SERVER,AIO_SERVERPORT,AIO_USERNAME,AIO_KEY); 


/****************************** Feeds ***************************************/ 
// Setup a feed called 'voltage' for publishing. 
// Notice MQTT paths for AIO follow the form: <username>/feeds/<feedname> 
Adafruit_MQTT_Publish voltage = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/TTS Analog"); 
// Setup a feed called 'onoff' for subscribing to changes. 
Adafruit_MQTT_Subscribe onoffbutton = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/onoff"); 

Adafruit_MQTT_Subscribe slider = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/ttsslider"); 
/*************************** Sketch Code ************************************/ 
int x = 0; 
int LED = D7; 
int anaLED= D3;


void setup()  
{ 
   Serial.begin(9600); 
   delay(10); 
   
   pinMode(A0,INPUT); 
   pinMode(LED, OUTPUT);
   pinMode(anaLED, OUTPUT);
   
   Serial.println(F("Adafruit MQTT demo")); 
   
   // Setup MQTT subscription for onoff feed. 
   mqtt.subscribe(&onoffbutton); 
   mqtt.subscribe(&slider); 
   
} 
void loop() 
{ 
   int value=analogRead(A0); 
 if( mqtt.Update() ){ 
       voltage.publish(value); 
 } 
 
  Adafruit_MQTT_Subscribe *subscription;
  while ((subscription = mqtt.readSubscription(5000))) {
    // Check if its the onoff button feed
    if (subscription == &onoffbutton) {
      Serial.print(F("On-Off button: "));
      Serial.println((char *)onoffbutton.lastread);
      
      if (strcmp((char *)onoffbutton.lastread, "ON") == 0) {
        digitalWrite(LED, LOW); 
      }
      if (strcmp((char *)onoffbutton.lastread, "OFF") == 0) {
        digitalWrite(LED, HIGH); 
      }
    }
    
      
     // check if its the slider feed
    if (subscription == &slider) {
      Serial.print(F("Slider: "));
      Serial.println((char *)slider.lastread);
      uint16_t sliderval = atoi((char *)slider.lastread);  // convert to a number
      analogWrite(anaLED, sliderval);
        Serial.print(sliderval);

    }
    
    
  
  
}
   delay(5000); 
} 
