#include <Arduino.h>
#include <SoftwareSerial.h>
#include "motor.h"

Motor motorL(4, 5);
Motor motorR(7, 6);

SoftwareSerial esp(2, 3);

void setup() {
  Serial.begin(9600);
  esp.begin(9600);

  Serial.println("Hello!");
  
  motorL.setSpeed(40);
  motorR.setSpeed(40);
}

long time = micros();

void forward() {
  motorL.go(FWD);
  motorR.go(FWD);
}

void backward() {
  motorL.go(REV);
  motorR.go(REV);
}

void turnLeft() {
  motorL.go(FWD);
  motorR.go(REV);
}

void turnRight() {
  motorL.go(REV);
  motorR.go(FWD);
}

void stop() {
  motorL.stop();
  motorR.stop();
}

void loop() {
  if(esp.available()) {
    char command = esp.read();
    switch (command)
    {
    case 'f':
        forward();
      break;
      case 'b':
        backward();
      break;
      case 'l':
        turnLeft();
      break;
      case 'r':
        turnRight();
      break;
      case 's':
        stop();
      break;
    default:
      break;
    }
  }
  delay(100);
}