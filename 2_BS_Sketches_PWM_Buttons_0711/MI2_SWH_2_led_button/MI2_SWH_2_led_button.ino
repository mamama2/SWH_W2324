//Sketching mit Hardware WS 23_24 - DMP_B7
//Beispiel eines Tasters am Arduino mit Ausgabe auf der konsole(Üb.2.2)
//Martinez
//Simple LED Switch Circuit
//This project demonstrates how a push  button switch can be used to turn an LED ON/OFF an print a message on the console (Serial Port)


//Set the LED Pin constant globally
//The LED is connected to Pin 10 of the Arduino
#define LEDPin 10
//Connected to one pin of the switch
#define ButtonPin 7

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  // initialize LED Pin as an output.
  pinMode(LEDPin, OUTPUT);
  //set the Button Pin as an input
  pinMode(ButtonPin, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  if (digitalRead(ButtonPin) == LOW) {
    digitalWrite(LEDPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  } else {
  digitalWrite(LEDPin, LOW);    // turn the LED off by making the voltage LOW
  }
  delay(500);
   // print the value of the button
  Serial.print("Button: ");
  Serial.print(digitalRead(ButtonPin));
  Serial.print("   ");
   // delay(500);
}
