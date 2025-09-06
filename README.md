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
- DC power source (5V 1A Adaptor) (Batteries can also be used instead of adaptor for portability)
- DC power jack adaptor connector plug female

## Circuit and Wiring
The IR sensors detect the line by sensing the reflected infrared light. The Arduino processes the sensor inputs and controls the motor driver shield to adjust the motors' speed and direction, enabling the robot to follow the line smoothly. (See instructions)

## Code Overview
- Sensor pins defined as LEFT_SENSOR (2), CENTER_SENSOR (3), RIGHT_SENSOR (7).
- Motor PWM and direction pins defined to Arduino PWM pins 10,11 for speed and digital pins 12,13 for direction.
- Logic moves motors forward, or turns left/right based on IR sensor inputs.
- If sensors lose line, the robot searches by turning in the last detected direction until line found.
- Motor functions control speed and direction using PWM and digital signals.

## How to Use
1. Connect the components as per the circuit diagram.
2. Upload the Arduino code (`code.ino`) to the Arduino Uno using the Arduino IDE.
3. Place the robot on a track with a black line on a white surface.
4. Power the robot and it will follow the line automatically.

## Future Improvements
- Add PID control for smoother line following.
- Implement obstacle avoidance features.
- Improve chassis design for better stability.
