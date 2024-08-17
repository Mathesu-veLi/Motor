#include <Arduino.h>
#include <Motor.h>

Motor::Motor(int pinL, int pinR) {
  this->pinL = pinL;
  this->pinR = pinR;
  this->defaultSpeed = 127;

  pinMode(pinL, OUTPUT);
  pinMode(pinR, OUTPUT); 
}

Motor::Motor(int pinL, int pinR, int defaultSpeed) {
  this->pinL = pinL;
  this->pinR = pinR;
  this->defaultSpeed = defaultSpeed;

  pinMode(pinL, OUTPUT);
  pinMode(pinR, OUTPUT); 
}

void Motor::forward(int speed) {
  analogWrite(pinL, speed);
  digitalWrite(pinR, LOW);
}

void Motor::forward() {
  this->forward(defaultSpeed);
}

void Motor::back(int speed) {
  digitalWrite(pinL, LOW);
  analogWrite(pinR, speed);
}

void Motor::back() {
  this->back(defaultSpeed);
}

void Motor::stop() {
  digitalWrite(pinL, LOW);
  digitalWrite(pinR, LOW);
}
