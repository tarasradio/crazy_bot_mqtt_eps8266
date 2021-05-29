#include "motor.h"

Motor::Motor(uint8_t dirPin, uint8_t speedPin)
{
	this->dirPin = dirPin;
	this->speedPin = speedPin;
	
	pinMode(dirPin, 1);
	pinMode(speedPin, 1);
}

void Motor::setSpeed(uint8_t speed)
{
  this->speed = speed;
}

void Motor::go(uint8_t dir)
{
	digitalWrite(dirPin, dir);
  analogWrite(speedPin, speed);
}

void Motor::stop()
{
	analogWrite(speedPin, 0);
}
