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
#define AIO_USERNAME    "xxxx"        //  replace with your user name
#define AIO_KEY         "xxxxxx"      // replace with your key..this is a long alphanumeric string


/************ Global State (you don't need to change this!) ***   ***************/ 
TCPClient TheClient; 

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details. 
Adafruit_MQTT_SPARK mqtt(&TheClient,AIO_SERVER,AIO_SERVERPORT,AIO_USERNAME,AIO_KEY); 


/****************************** Feeds ***************************************/ 
// Setup a feed called 'voltage' for publishing. 
// Notice MQTT paths for AIO follow the form: <username>/feeds/<feedname> 

Adafruit_MQTT_Publish voltage = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/TTS Analog"); 


/*************************** Sketch Code ************************************/ 
int x = 0; 
void setup()  
{ 
   Serial.begin(115200); 
   delay(10); 
   pinMode(A0,INPUT); 
   Serial.println(F("Adafruit MQTT demo")); 
    
} 
void loop() 
{ 
   int value=analogRead(A0); 
 if( mqtt.Update() ){ 
       voltage.publish(value); 
 } 
   delay(10000); 
} 
