# CONVEX-DETECTION-BOT

## Overview
The Convex Detection Bot is an Arduino-based autonomous vehicle designed to detect convex obstacles using ultrasonic sensors and navigate accordingly. The boat intelligently maneuvers based on real-time sensor data, making it useful for autonomous navigation applications.

## Features
- Obstacle Detection: Uses ultrasonic sensors to detect convex obstacles in its path.
- Autonomous Navigation: Adjusts movement dynamically to avoid detected obstacles.
- LED Indicators: Signals critical conditions, such as complete rotations or blocked paths.
- Motor Control: Controls motor speed and direction based on sensor feedback.

## Components Used
- Arduino Uno
- Ultrasonic Sensors (HC-SR04)
- Motor Driver (L298N)
- DC Motors
- LED Indicators
- Power Supply
- Custom PCB (Designed & Fabricated as part of the project)

## Code Implementation
The project's main logic is implemented in the Arduino code. The boat:
1. Continuously reads ultrasonic sensor data.
2. Determines if an obstacle is present.
3. Adjusts its movement (forward, turn left, or turn right) based on obstacle detection.
4. Stops in case of complete rotation (360-degree movement) or if an object is too close.

## My Role in the Project
- Coding & Development: Worked in collaboration with teammates on the Arduino code for motor control and obstacle detection.
- PCB Design & Fabrication: Contributed to designing and fabricating the circuit board.

## Video Demonstration
Check out the working demonstration of the project here:
(https://drive.google.com/drive/folders/1ms64hAYMmi_6JH2KPJnYmjJuN5tXWMbR?usp=sharing)

## Potential Enhancements
- Improved Navigation Algorithm: Optimize movement for smoother obstacle avoidance.
- GPS Integration: Enable predefined path navigation.
- Wireless Control: Add remote-control functionality for manual override.
- Battery Efficiency2: Enhance power management for longer operational time.






