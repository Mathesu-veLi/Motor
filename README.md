# 🚀 Motor Library for Arduino

A simple yet powerful library for DC motor control with Arduino. 🛠️

## 📦 Installation
1. ⬇️ Download `Motor.h` and `Motor.cpp`  
2. 📂 Place them in your Arduino project folder  
3. ➕ Include in your sketch: `#include <Motor.h>`  

## 🎮 Basic Usage

### Single Motor Control Example
```cpp
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
```

## 🚀 Advanced Usage

### Differential Drive Robot Example
```cpp
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
```

## 🏗️ Constructors
| Constructor | Description |
|-------------|-------------|
| `Motor(pinL, pinR)` | Basic setup with default speed (127) |
| `Motor(pinL, pinR, speed)` | Setup with custom default speed |

## ⚙️ Core Methods
| Method | Action |
|--------|--------|
| `forward(speed)` | ▶️ Move forward (0-255 PWM) |
| `forward()` | ▶️ Move forward (default speed) |
| `back(speed)` | ◀️ Move backward (0-255 PWM) |
| `back()` | ◀️ Move backward (default speed) |
| `stop()` | ⏹️ Immediate stop |

## 💡 Pro Tips
- 🔋 Always use external power for motors > 500mA
- 🛡️ Add flyback diodes for protection
- 🔌 PWM pins vary by board (3,5,6,9,10,11 on Uno)
- ⚡ Max speed = 255, min speed = 0 (stop)
- 🤖 For robots, calibrate motor speeds individually

Developed with ❤️ for the Arduino community 🎉
