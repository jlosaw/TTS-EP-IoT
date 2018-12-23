// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h>



#define DHTPIN 2     // what pin we're connected to for the DHT


#define DHTTYPE DHT11		// Define sensor as DHT 11 

float h;
float f;
float t;

int hightemp = 80;      //high temp threshold
int lowtemp = 42;       // low temp threshold
int led=D7;             //onboard LED
int buzz=D1;            //optional buzzer or haptic motor

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    
  pinMode (led, OUTPUT);
  pinMode (buzz, OUTPUT);
	dht.begin();
	Particle.function("heater", heater);    //A Particle function we can use to take an input from the dashboard to fire up the heater
}

void loop() {

//Get your temps

	h = dht.getHumidity();
// Read temperature as Celsius
	t = dht.getTempCelcius();
// Read temperature as Farenheit
	f = dht.getTempFarenheit();
  
// Check if any reads failed and exit early (to try again).
	if (isnan(h) || isnan(t) || isnan(f)) {
		Serial.println("Failed to read from DHT sensor!");
		return;
	}

//Publish the temp data to the console
Particle.publish("TTStemperature",String (f),60,PRIVATE);
Particle.publish("TTShumidity",String (h),60,PRIVATE);

// Wait a few seconds between measurements.
	delay(5000);

}

//Command to fire up our "heater"

int heater(String command) {
  
  
  if (command=="on") {
        digitalWrite(led,HIGH);
        digitalWrite(buzz,HIGH);
        delay (2000);
        digitalWrite(led,LOW);
        digitalWrite(buzz,LOW);
        return 1;
    }
    
    else{

        digitalWrite(led,LOW);
        digitalWrite(buzz,LOW);
    }

}
