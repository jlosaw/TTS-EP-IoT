// In this sketch we combine reading the input from the rotary pot with the output of 
// the display...However, we have a slight problem to overcome


#include <Grove_OLED_128x64.h>

#if defined (SPARK)
// Nothing to include if Spark
#else
#include <Wire.h>               //this is the library that drives the I2C connection
#include <avr/pgmspace.h>
#endif

#define ROTARYPIN A0            //add the rotary pin back in

void setup()
{
  Wire.begin();                         // open the I2C connection
  SeeedOled.init();                     //initialze SEEED OLED display
  SeeedOled.clearDisplay();              //clear the screen and set start position to top left corner
  SeeedOled.setNormalDisplay();          //Set display to normal mode (i.e non-inverse mode)
  SeeedOled.setPageMode();              //Set addressing mode to Page Mode
  SeeedOled.setTextXY(0,0);              //Set the cursor to Xth Page, Yth Column (upper left in this case)
  SeeedOled.putString("Analog Reading"); //Print the String

}

void loop()
{
    int analogValue = analogRead(ROTARYPIN);
    
    //SeeedOled.setTextXY(1,0);             //start with these 2 lines commented out
    //SeeedOled.putString("    ");          //this one too
    SeeedOled.setTextXY(1,0);               //move cursor to the next line
    SeeedOled.putNumber(analogValue);       //what is the problem when we do it this way??
  
    delay(100);                             //delay for a bit
   
}
