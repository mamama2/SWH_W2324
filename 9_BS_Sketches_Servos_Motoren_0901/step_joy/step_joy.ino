#include <Stepper.h>
#define SLEEP 7 // Pin 7 connected to SLEEP pin
#define X_pin A0 // Pin A0 connected to joystick x axis
 #define STEPS 1025

int direction; // Variable to set Rotation (CW-CCW) of the motor
int steps = 1025; // Assumes the belt clip is in the Middle
 // define stepper motor control pins
#define IN1 5
#define IN2 6
#define IN3 7
#define IN4 8

 Stepper stepper(STEPS, IN4, IN2, IN3, IN1);

void loop () {
        int val = analogRead(X_pin);

  while (analogRead (X_pin) >= 0 && analogRead (X_pin) <= 100) {
    if (steps> 0) {
       // map the speed between 5 and 500 rpm
      int speed_ = map(val, 500, 0, 5, 500);
      // set motor speed
      stepper.setSpeed(speed_);

      // move the motor (1 step)
      stepper.step(-10);

     // val = analogRead(joystick);
    
      steps--;
    }
  }
  
    while (analogRead (X_pin)> 100 && analogRead (X_pin) <= 400) {
      if (steps <512) {
       
        steps ++;
      }
      if (steps> 512) {
       
        steps--;
      }
    }
      
    while (analogRead (X_pin)> 401 && analogRead (X_pin) <= 600) {
      if (steps <1025) {
       digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
        steps ++;
      }
      if (steps> 1025) {
       digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
        steps--;
      }
    }
 
    while (analogRead (X_pin)> 601 && analogRead (X_pin) <= 1024) {
      if (steps <1535) {
           // map the speed between 5 and 500 rpm
      int speed_ = map(val, 523, 1023, 5, 500);
      // set motor speed
      stepper.setSpeed(speed_);

      // move the motor (1 step)
      stepper.step(10);
        steps ++;
      }
      if (steps> 1535) {
          // map the speed between 5 and 500 rpm
      int speed_ = map(val, 523, 1023, 5, 500);
      // set motor speed
      stepper.setSpeed(speed_);

      // move the motor (1 step)
      stepper.step(10);
        steps--;
      }
    }
   

}