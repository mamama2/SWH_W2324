/*
  SKETCHING MIT HARDWARE
     DMP - WS 23_24
  - DEMO 2: Einparkenhilfe mini-Projekt
  This project demonstrates how to measure distances
  using a ultrasonic sensor
  Martinez
*/
#include<Wire.h>
#include <LCD.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 
# define LAUTSPRECHER 4
# define LED 13
# define SENDEN 6
# define ECHO 7

void setup()
{
  lcd.begin(16,2); // Initializes the interface to the LCD screen
  lcd.backlight();
  pinMode(SENDEN, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LAUTSPRECHER, OUTPUT);
  pinMode(LED, OUTPUT);
}

void loop()
{
  // Funktion aufrufen
  long Entfernung = EntfernungMessen();
  // Messfehler ausschließen
   lcd.setCursor(0,0);
  lcd.print("Distance: "); 
  lcd.print(Entfernung);
  lcd.print(" cm");

  // Draws bargraph on the second line of the LCD
  lcd.setCursor(0,1);
 
  if (Entfernung < 100)
  {
    switch (Entfernung)
    {
      case 23 ... 45:
        tone(LAUTSPRECHER, 1000, 400);
        digitalWrite(LED, HIGH);
        delay(250);
        digitalWrite(LED, LOW);
        delay(500);
        break;
      case 11 ... 22:
        tone(LAUTSPRECHER, 1000, 200);
        digitalWrite(LED, HIGH);
        delay(10);
        digitalWrite(LED, LOW);
        delay(200);
        break;
      case 1 ... 10:
        tone(LAUTSPRECHER, 1000, 20);
        digitalWrite(LED, HIGH);
        delay(50);
        digitalWrite(LED, LOW);
        delay(100);
        break;
    }
  }
}
int EntfernungMessen()
{
  long Entfernung = 0;

  // Sender kurz ausschalten um Störungen des Signal zu vermeiden
  digitalWrite(SENDEN, LOW);
  delay(5);
  // Signal senden
  digitalWrite(SENDEN, HIGH);
  delayMicroseconds(10);
  digitalWrite(SENDEN, LOW);
  // pulseIn -> Zeit messen, bis das Signal zurückkommt
  long Zeit = pulseIn(ECHO, HIGH);
  // Entfernung in cm berechnen
  Entfernung = (Zeit / 2) * 0.03432;
  return Entfernung;
}
