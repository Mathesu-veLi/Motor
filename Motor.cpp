#include <Arduino.h>
#include <Motor.h>

Motor::Motor(int pinL, int pinR) {
  this->pinL = pinL;
  this->pinR = pinR;

  pinMode(pinL, OUTPUT);
  pinMode(pinR, OUTPUT); 
}
