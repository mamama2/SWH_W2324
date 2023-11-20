/*
   Sketching mit Hardware
  DMP - Vertiefung Medieninformatik 2 - WS 23_24
  - Using the delay() function. Termin 5
  This project illustrates the problem with the delay
  function on how it blocks our arduino. 2 Blinking LED + a pushbutton to change the state
  Martinez
*/
int led1 = 6;
int led2 = 7;
int button = 2;



void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(button, INPUT_PULLUP);

}

void loop() {
  digitalWrite(led1, HIGH);
  delay(1000);
  digitalWrite(led1, LOW);
  delay(1000);

  if (!digitalRead(button)) {
    digitalWrite(led2, HIGH);
    delay(2000);
    digitalWrite(led2, LOW);
  }
}
