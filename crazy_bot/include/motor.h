#ifndef motor_h
#define motor_h

#include <Arduino.h>

enum Direction {
	FWD,
	REV
};

class Motor {
private:
	uint8_t dirPin, speedPin; 
	int8_t speed = 50;
public:
	Motor() {}
	Motor(uint8_t dirPin, uint8_t speedPin);
	void setSpeed(uint8_t speed);
	void go(uint8_t dir);
	void stop();
};

#endif
