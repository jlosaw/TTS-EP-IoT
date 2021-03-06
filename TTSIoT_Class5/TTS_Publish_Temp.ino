// Add the DHT library to the sketch
#include "Adafruit_DHT.h"


#define DHTPIN 2     // what pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11		// DHT 11 
//#define DHTTYPE DHT22		// DHT 22 (AM2302)
//#define DHTTYPE DHT21		// DHT 21 (AM2301)

float h;
float f;
float t;

int hightemp = 80;      //high temp threshold
int lowtemp = 42;       // low temp threshold

DHT dht(DHTPIN, DHTTYPE);

void setup() {

	dht.begin();
}

void loop() {
// Wait a few seconds between measurements.
	delay(5000);


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
Particle.publish("Temp_F",String (f),60,PRIVATE);
Particle.publish("Humidity",String (h),60,PRIVATE);


//Publish an event if the temp goes out of spec

if (f>hightemp) {
        Particle.publish("JLO_Temp","high");
    }
    
    
if (f<lowtemp) {
        Particle.publish("JLO_Temp","low");
    }

if (f>=60 && f<70){
        Particle.publish("JLOGH_Temp","60");
}

if (f>=70 && f<80){
        Particle.publish("JLOGH_Temp","70");
}

if (f>=80 && f<90){
        Particle.publish("JLOGH_Temp","80");
}

else {
}

}


