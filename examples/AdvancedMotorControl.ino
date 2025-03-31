/*
 * DifferentialDrive - Advanced Motor Library Example
 * Controls two motors for robotic applications
 * 
 * Connections:
 * - Left Motor:  pinL=5, pinR=6
 * - Right Motor: pinL=9, pinR=10
 * - Motor driver power to appropriate power source
 */

#include <Motor.h>

// Create motor instances with different default speeds
Motor leftMotor(5, 6, 180);   // Left motor (higher default speed)
Motor rightMotor(9, 10, 150); // Right motor

void setup() {
  Serial.begin(9600);
  Serial.println("Differential Drive Example Started");
}

void loop() {
  // Forward movement
  Serial.println("Moving FORWARD");
  leftMotor.forward();
  rightMotor.forward();
  delay(2000);
  
  // Pivot right
  Serial.println("Pivoting RIGHT");
  leftMotor.forward(200);
  rightMotor.back(150);
  delay(1000);
  
  // Stop briefly
  Serial.println("Stopping motors");
  leftMotor.stop();
  rightMotor.stop();
  delay(500);
  
  // Backward movement
  Serial.println("Moving BACKWARD");
  leftMotor.back();
  rightMotor.back();
  delay(2000);
  
  // Full stop for 3 seconds
  Serial.println("Full stop for 3 seconds");
  leftMotor.stop();
  rightMotor.stop();
  delay(3000);
}
