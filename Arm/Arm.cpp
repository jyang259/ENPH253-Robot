/*
	Arm.h - Library for arm actuation.
	Created by Team Calgary
*/

#include "Arduino.h"
#include "Claw.h"
#include "Servo.h"

//Input: pin input for arm servo
Arm::Arm(int pin)
{
	_pinArm = pin;
}

//