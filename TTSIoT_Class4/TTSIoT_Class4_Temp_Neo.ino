
/* ======================= includes ================================= */

#include "Particle.h"
#include <math.h>         //include or you can't do the log function
#include <neopixel.h>
#include "application.h"

SYSTEM_MODE(AUTOMATIC);




// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_PIN D6
#define PIXEL_COUNT 12
#define PIXEL_TYPE WS2811       //2811 is fine for ours, but if you use a different brand you need to look this up in the library file
#define BRIGHTNESS 50           // 0 - 255 (note, these are super bright, so lower is fine for the bench)

Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

// name the pin for the temp sensor
#define TEMPPIN A4

void setup() {


  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  Serial.begin(9600);
}

void loop() {
  // Some example procedures showing how to display to the pixels:
  // Do not run more than 15 seconds of these, or the b/g tasks
  // will be blocked.
  // --------------------------------------------------------------

  int B = 3975;                                 // B value of the thermistor

  int analogValue = analogRead(TEMPPIN);        // read rotary pin
  float resistance=(float)(4095-analogValue)*10000/analogValue;   //get the resistance of the sensor
  float temperature=1/(log(resistance/10000)/B+1/298.15)-273.15;  //convert to temperature via datasheet
  Serial.print("analogValue: ");
  Serial.println(analogValue);
  Serial.print("resistance: ");
  Serial.println(resistance);
  Serial.print("temperature: ");
  Serial.println(temperature);
  Serial.println("");

  //create a gradient for the temperature

  if(temperature>22){
    strip.setPixelColor(0, 25,70,70);
    strip.show();
  }
  // turn off the pixel if the temp falls
  
  else{
    strip.setPixelColor(0, 0,0,0);
    strip.show();
  }

  if(temperature>23){
    strip.setPixelColor(1, 0,255,255);
    strip.show();
  }

  else{
    strip.setPixelColor(1, 0,0,0);
    strip.show();
  }

  if(temperature>24){
    strip.setPixelColor(2, 0,0,255);
    strip.show();
  }

  else{
    strip.setPixelColor(2, 0,0,0);
    strip.show();
  }

  if(temperature>25){
    strip.setPixelColor(3, 255,0,255);
    strip.show();
  }

  else{
    strip.setPixelColor(3, 0,0,0);
    strip.show();
  }

  if(temperature>26){
    strip.setPixelColor(4, 255,0,0);
    strip.show();
  }

  else{
    strip.setPixelColor(4, 0,0,0);
    strip.show();
  }

  if(temperature>27){
    strip.setPixelColor(5, 150 ,255,0);
    strip.show();
  }

  else{
    strip.setPixelColor(5, 0,0,0);
    strip.show();
  }

  if(temperature>28){
    strip.setPixelColor(6, 0 ,255,0);
    strip.show();
  }

  else{
    strip.setPixelColor(6, 0,0,0);
    strip.show();
  }

  delay(200);

}
