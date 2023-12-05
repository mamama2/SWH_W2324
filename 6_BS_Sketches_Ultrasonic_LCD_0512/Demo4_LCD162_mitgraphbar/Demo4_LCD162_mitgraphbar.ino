/*
  SKETCHING MIT HARDWARE
     DMP - WS 23_24
  - Demo 4 : Bargraph-Library
  This project demonstrates how to use the Library Bargraph
  with a LCD Display
  Martinez
*/

#include <LiquidCrystal.h>
#include <LcdBarGraph.h>

byte lcdNumCols = 16; // -- number of columns in the LCD
byte sensorPin = A0; // -- value for this example

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // -- creating LCD instance
LcdBarGraph lbg(&lcd, lcdNumCols);  // -- creating bargraph instance, format is (&lcd, lcdNumCols, start X, start Y). So (&lcd, 16, 0, 1) would set the bargraph length to 16 columns and start the bargraph at column 0 on row 1.

void setup() {
  // -- initializing the LCD
  lcd.begin(2, lcdNumCols);
  lcd.clear();
  // -- do some delay some time I've got broken visualization
  delay(100);
}

void loop()
{
  // -- draw bar graph from the analog value readed
  lbg.drawValue( analogRead(sensorPin), 1024);
  // -- do some delay: frequent draw may cause broken visualization
  delay(100);
}
