/*
   SKETCHING MIT HARDWARE
     DMP - WS 22/23
   Demo 2 : LCD Display
  Martinez
*/
#include <Wire.h> // Wire Bibliothek einbinden
#include <LiquidCrystal_I2C.h> // Vorher hinzugefügte LiquidCrystal_I2C Bibliothek einbinden
LiquidCrystal_I2C lcd(0x27,16, 2); //Hier wird festgelegt um was für einen Display es sich handelt. In diesem Fall eines mit 16 Zeichen in 2 Zeilen und der HEX-Adresse 0x27. Für ein vierzeiliges I2C-LCD verwendet man den Code "LiquidCrystal_I2C lcd(0x27, 20, 4)" 
#include <LcdBarGraph.h>;
byte lcdNumCols = 16;

LcdBarGraph lbg(&lcd, lcdNumCols,0,1); 
// Variable für Zeit und Entfernung initialisieren
long Zeit;
long Entfernung;
// statt
// int SENDEN = 6;
// int ECHO = 7;
# define SENDEN 6
# define ECHO 7
# define LAUTSPRECHER 13
void setup() 
{
   Serial.begin(9600);
   pinMode(13, OUTPUT);     // initialize digital pin 13 as an output.
  digitalWrite(13, HIGH);
 pinMode(SENDEN, OUTPUT);
 pinMode(ECHO, INPUT);
lcd.init(); //Im Setup wird der LCD gestartet 
lcd.backlight(); //Hintergrundbeleuchtung einschalten (lcd.noBacklight(); schaltet die Beleuchtung aus). 
//lcd.setCursor(0, 0);
// lcd.print("Entfernung messen");
}

void loop() 
{ 
  lcd.setCursor(0, 0);


 lcd.print("Entfernung: ");
  lcd.setCursor(1, 1);
 lcd.print(Entfernung);
 lcd.print(" cm ");
//lcd.setCursor(0, 0);//Hier wird die Position des ersten Zeichens festgelegt. In diesem Fall bedeutet (0,0) das erste Zeichen in der ersten Zeile. 
//lcd.print("Funduino GmbH"); 
//lcd.setCursor(0, 1);// In diesem Fall bedeutet (0,1) das erste Zeichen in der zweiten Zeile. 
//lcd.print("Viel Erfolg!"); 
// Sender kurz ausschalten um Störungen des Signals zu vermeiden
 digitalWrite(SENDEN, LOW);
 delay(10);
 // Signal für 10 Mikrosekunden senden
 digitalWrite(SENDEN, HIGH);
 delayMicroseconds(10);
 // Sender ausschalten
 digitalWrite(SENDEN, LOW);
 // pulseIn → Zeit messen, bis das Signal zurückkommt
 Zeit = pulseIn(ECHO, HIGH);
 /* Entfernung in cm berechnen
 Zeit/2 → nur eine Strecke soll berechnet werden
 Umrechnung in cm
 */
 Entfernung = (Zeit / 2) * 0.03432;

 // 400 cm ist die maximal messbare Entfernung
 if (Entfernung < 100)
 {
 // Ausgabe auf dem Seriellen Monitor
 Serial.print ("Entfernung: ");
 Serial.print(Entfernung);
 Serial.println(" cm");

 delay(100);
 switch (Entfernung)
 {
  case 1 ... 4:
 tone(LAUTSPRECHER, 1000, 500);
 //digitalWrite(LED, HIGH);
 delay(50);
 //digitalWrite(LED, LOW);
 delay(100);
 break;
 case 5 ... 15:
 tone(LAUTSPRECHER, 1000, 300);
 //digitalWrite(LED, HIGH);
 delay(50);
 //digitalWrite(LED, LOW);
 delay(200);
 break;
 case 16 ... 22:
 tone(LAUTSPRECHER, 1000, 200);
// digitalWrite(LED, HIGH);
 delay(50);
 //digitalWrite(LED, LOW);
 delay(400);
 break;
 case 23 ... 40:
 tone(LAUTSPRECHER, 1000, 100);
 //digitalWrite(LED, HIGH);
 delay(50);
// digitalWrite(LED, LOW);
 delay(600);
 break;
  
 }
 }
 
 
} 
