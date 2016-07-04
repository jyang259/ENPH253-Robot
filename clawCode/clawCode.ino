/*
Code for claw mechanism 
*/

#include <Servo.h>

int servoPin = 1

Servo servo; 

int pos = 0; //servo position in degrees

void setup() {
  // put your setup code here, to run once:
  servo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  //scan from 0 to 180 degrees
  //scan back from 180 to 0 degrees
  for(pos = 0; pos < 180; pos++)
  {
    servo.write(pos);
    delay(15);
  }
  
  for(pos = 180; pos > 0; pos pos--)
  {
    servo.write(pos);
    delay(15);
  }
}
