# Line Follower Robot

## Description
This project is a simple Line Follower Robot built using an Arduino Uno, three IR sensors, an L298P motor driver shield, two DC motors, one castor wheel, and a self-made hardboard chassis. The robot uses the IR sensors to detect a black line on the floor and follows it by controlling the motors accordingly.

## Components
- Arduino Uno
- 3 IR sensors
- L298P motor driver shield
- 2 DC motors
- 1 Castor wheel
- Hardboard chassis (self-made)
- Jumper wires
- DC power source (5V 1A Adaptor)

## Circuit and Wiring
The IR sensors detect the line by sensing the reflected infrared light. The Arduino processes the sensor inputs and controls the motor driver shield to adjust the motors' speed and direction, enabling the robot to follow the line smoothly.

## Code Overview
The Arduino code reads the three IR sensors and applies logic to control the motors via the L298P driver. The motors move forward, turn left, or turn right based on the line position detected by the sensors.

## How to Use
1. Connect the components as per the circuit diagram (to be added).
2. Upload the Arduino code (`code.ino`) to the Arduino Uno using the Arduino IDE.
3. Place the robot on a track with a black line on a white surface.
4. Power the robot and it will follow the line automatically.

## Future Improvements
- Add PID control for smoother line following.
- Implement obstacle avoidance features.
- Improve chassis design for better stability.
