#include <LiquidCrystal.h>
//#include <Claw.h>
#include <phys253.h>

//Claw claw(0);
int pos = 0;
int pinIR = 1;
int pinMotor = 0;
double thresholdIRSignal = 2.0;
double currentIRSignal = 0;
double lastPosition;
double strongestIRSignal = 0;
double locationStrongestIRSignal1 = 0;
double locationStrongestIRSignal2 = 0;

void setup() {
#include <phys253setup.txt>

  ServoTimer2 RCServo0; //Controls ascending and descending of arm
  ServoTimer2 RCServo1; //Controls claw actuation

  //Initial positions
  RCServo0.write(180); //Arm starts up
  RCServo1.write(180); //Claw starts open
  //RCServo0.attach(0);
  //pinMode(0, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  //locationIRSignal = RCServo0.read();
  strongestIRSignal = analogRead(pinIR);

  //Base rotation - Find the direction of the strongest IR signal
  if (strongestIRSignal > thresholdIRSignal) {

    while (true) {
      motor.speed(pinMotor, 25);
      currentIRSignal = analogRead(pinIR);
      if (currentIRSignal > strongestIRSignal) {
        strongestIRSignal = currentIRSignal;
        locationStrongestIRSignal1 = RCServo0.read();
      }
      if (currentIRSignal < strongestIRSignal) {
        motor.stop(pinMotor);
        break;
      }
    }
  }

  //Arm height - lower arm to height of passenger
  RCServo0.write(180);
  LCD.clear();
  LCD.print(180);
  delay(1000);

  //TODO - Arm extension

  //Claw closure - picking up passenger
  RCServo1.write(90);
  LCD.clear();
  LCD.print(90);
  delay(1000);


  //    delay(1000);
  //hold claw in closed position
  //RCServo0.detach();
}
