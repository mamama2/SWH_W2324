/*
   Sketching mit Hardware
  DMP - Vertiefung Medieninformatik 2 - WS 23_24
  
  - Using the millis() function Termin 5
  This project demonstrates the usage of the
  millis() function in otder to avoid using delay()
 Martinez
*/
/* NOGO
void setup() {

  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  if (digitalRead(2) == HIGH){
    digitalWrite(6, !digitalRead(6)); // Schaltet LED an pin 4 AN/AUS
  }
  digitalWrite(7, HIGH); // LED an Pin 3 AN  
  delay(1000); // Pause            
  digitalWrite(7, LOW); // LED an Pin 3 AUS    
  delay(1000); // Pause            
} */
unsigned long previousMillis = 0; // speichert den Zeitpunkt an dem zuletzt geschalten wurde
const long interval = 1000; // Länge der Pause in ms

void setup() {
  pinMode(6, OUTPUT); // LED 1
  pinMode(7, OUTPUT); // LED 2
  pinMode(2, INPUT);  // Taster
}

void loop() {
  if (digitalRead(2) == HIGH){
    digitalWrite(6, !digitalRead(6)); // Schaltet LED an pin 4 AN/AUS
  }
 unsigned long currentMillis = millis(); // Aktuelle Zeit wird in currentMillis gespeichert
  if (currentMillis - previousMillis >= interval) { // Falls mehr als 1000 ms vergangen sind
     previousMillis = currentMillis; // Zeitpunkt der letzten Schaltung wird festgehalten 
  digitalWrite(7, !digitalRead(7)); // LED wird ein- bzw. ausgeschaltet
  }
}