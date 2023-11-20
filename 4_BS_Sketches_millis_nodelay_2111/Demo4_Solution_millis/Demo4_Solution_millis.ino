// SKETCHING WITH HARDWARE - WS 23_24
// Solution to delay()
//

unsigned long previousTime = millis(); // or 0
unsigned long timeInterval = 500;
void setup() {
  Serial.begin(115200);

}

void loop() {
  unsigned long timeNow = millis(); // we check everytime in the loop the current time
  if (timeNow - previousTime > timeInterval) {

    Serial.println("Hello"); // print hello every 500ms
    //No delay!!!
    Serial.println(millis()); 
    //previousTime = timeNow;
        previousTime += timeInterval;

  }
}
