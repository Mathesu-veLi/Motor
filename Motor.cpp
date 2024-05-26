#include <Arduino.h>
#include <Motor.h>

Motor::Motor(int pinL, int pinR) {
  this->pinL = pinL;
  this->pinR = pinR;

  pinMode(pinL, OUTPUT);
  pinMode(pinR, OUTPUT); 
}

void Motor::forward() {
  analogWrite(pinL, 150);
  digitalWrite(pinR, LOW);
}

void Motor::forward(int speed) {
  analogWrite(pinL, speed);
  digitalWrite(pinR, LOW);
}

void Motor::back() {
  digitalWrite(pinL, LOW);
  analogWrite(pinR, 150);
}

void Motor::stop() {
  digitalWrite(pinL, LOW);
  digitalWrite(pinR, LOW);
}