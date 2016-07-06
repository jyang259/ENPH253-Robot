/*
	Claw.h - Library for claw actuation.
	Created by Team Calgary
*/

#ifndef Claw_h
#define Claw_h

#include "Arduino.h"

class Claw
{
	public:
		void open();
		void close();
	private: 
		int _pinClaw;
};

#endif