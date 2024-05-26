#include <Arduino.h>
#include <Motor.h>

Motor::Motor(int pinL, int pinR) {
  this->pinL = pinL;
  this->pinR = pinR;

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

void Motor::forward() {
  analogWrite(pinL, defaultSpeed);
  digitalWrite(pinR, LOW);
}

void Motor::forward(int speed) {
  analogWrite(pinL, speed);
  digitalWrite(pinR, LOW);
}

void Motor::back() {
  digitalWrite(pinL, LOW);
  analogWrite(pinR, defaultSpeed);
}

void Motor::back(int speed) {
  digitalWrite(pinL, LOW);
  analogWrite(pinR, speed);
}

void Motor::stop() {
  digitalWrite(pinL, LOW);
  digitalWrite(pinR, LOW);
}