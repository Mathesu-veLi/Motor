/*
 * BasicMotorControl - Example for Motor Library
 * Demonstrates forward, backward, and stop functions with speed control
 * 
 * Connections:
 * - Motor pinL to Arduino pin 5
 * - Motor pinR to Arduino pin 6
 * - Motor driver power to appropriate power source
 */

#include <Motor.h>

// Create motor instance (pins 5 and 6, default speed 150)
Motor myMotor(5, 6, 150);

void setup() {
  // Serial monitor for feedback
  Serial.begin(9600);
  Serial.println("Basic Motor Control Example Started");
}

void loop() {
  Serial.println("Moving FORWARD at default speed (150)");
  myMotor.forward();
  delay(2000);
  
  Serial.println("Stopping motor");
  myMotor.stop();
  delay(1000);
  
  Serial.println("Moving BACKWARD at speed 200");
  myMotor.back(200);  // Override default speed
  delay(2000);
  
  Serial.println("Stopping motor");
  myMotor.stop();
  delay(1000);
  
  Serial.println("Moving FORWARD at speed 100");
  myMotor.forward(100);  // Override default speed
  delay(2000);
  
  Serial.println("Stopping motor for 3 seconds");
  myMotor.stop();
  delay(3000);
}
