/*
	Claw.h - Library for claw actuation.
	Created by Team Calgary
*/

#include "Arduino.h"
#include "Claw.h"
#include "Servo.h"

//Input: pin input for claw servo
Claw::Claw(int pin)
{
	pinMode(pin, OUTPUT);
	_pinClaw = pin;
}

//Open claw fully and hold 
void Claw::open()
{
	Servo servoClaw;
	servoClaw.attach(_pinClaw);

	//Open claw fully
	servoClaw.write(180);

	//hold claw in open position
	servoClaw.detach();

}

//Close claw around passenger and hold 
void Claw::close()
{
	Servo servoClaw;
	servoClaw.attach(_pinClaw);

	//Close claw around passenger
	servoClaw.write(90);

	//hold claw in closed position
	servoClaw.detach();
}