// This file is a simple sketch to display text on the OLED to verify that it
// is working properly


#include <Grove_OLED_128x64.h>
#if defined (SPARK)
// Nothing to include if Spark
#else
#include <Wire.h>
#include <avr/pgmspace.h>
#endif

void setup()
{
  Wire.begin();
  SeeedOled.init();  //initialze SEEED OLED display

  SeeedOled.clearDisplay();          //clear the screen and set start position to top left corner
  SeeedOled.setNormalDisplay();      //Set display to normal mode (i.e non-inverse mode)
  SeeedOled.setPageMode();           //Set addressing mode to Page Mode which is really the row
  SeeedOled.setTextXY(0,0);          //Set the cursor to Xth row , Yth Column
  SeeedOled.putString("Hello World"); //Print the String... change this print your own message

}

void loop()
{
}
