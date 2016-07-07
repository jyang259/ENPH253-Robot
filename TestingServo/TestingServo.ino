#include <Claw.h>
#include <Servo.h>

Claw claw(7);

void setup() {
}

void loop() {
  // put your main code here, to run repeatedly:
  claw.open();
  delay(100);
  claw.close();
  delay(100);
}
