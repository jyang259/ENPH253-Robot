/*
Code for claw mechanism 
*/

#include <Servo.h>

int servoArm = 1 //Servo for telescoping arm
int servoClaw = 2 //Servo for claw mechanism 

int microSwitch = 2//Microswitch for passenger detection

Servo servo; 

int pos = 0; //servo position in degrees

void setup() {
  // put your setup code here, to run once:
  servo.attach(servoPin);
  pinMode(microSwitch, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  //scan from 0 to 180 degrees
  
  /*for(pos = 0; pos < 180; pos++){
    servo.write(pos);
    delay(15);
  }
  
  //scan back from 180 to 0 degrees
  for(pos = 180; pos > 0; pos--){
    servo.write(pos);
    delay(15);
  }*/
  
  //microswitch
  if(digitalRead(microSwitch) == HIGH){
    for(pos=180; pos < 90; pos--){
      
    }
  }
  
}