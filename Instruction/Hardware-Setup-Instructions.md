## Hardware Setup Instructions

### 1. Mount Motor Driver Shield
- Place the L298P motor driver shield carefully on the Arduino Uno pins and press down to secure.

### 2. Connect IR Sensors
- Connect the sensor outputs to Arduino pins using jumper wires:
  - Left Sensor → Pin 2
  - Center Sensor → Pin 3
  - Right Sensor → Pin 7
- Connect VCC and GND of all sensors to Arduino 5V and GND.

### 3. Connect Motors to Driver Shield
- Connect left DC motor to Motor A terminals on the shield.
- Connect right DC motor to Motor B terminals on the shield.

---

## Sensor Placement & Calibration

- Place the three IR sensors evenly spaced about 2–3 cm apart across the front.
- Keep sensors approximately 1-1.5 cm above the ground surface.
- Adjust the onboard potentiometer on IR sensors to tune sensitivity for clean detection of black line vs white surface.
- Test sensor readings via Arduino Serial Monitor to confirm clear HIGH/LOW signals.

---

## Power Supply

- Power the motors and motor driver shield by supplying an external DC power source directly to the L298P motor driver shield's power input terminals.
