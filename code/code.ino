// === Sensor Pins ===
#define LEFT_SENSOR   2
#define CENTER_SENSOR 3
#define RIGHT_SENSOR  7

// === Motor A (Left Motor) ===
#define MOTOR_A_PWM 10
#define MOTOR_A_DIR 12  // HIGH = forward

// === Motor B (Right Motor) ===
#define MOTOR_B_PWM 11
#define MOTOR_B_DIR 13  // HIGH = forward

// === Speeds ===
#define fwd_speed 150
#define turn_high 200
#define turn_low 150

// === Direction tracking ===
char last_seen = 'C'; // 'L', 'C', 'R'

void setup() {
  Serial.begin(9600);

  pinMode(LEFT_SENSOR, INPUT);
  pinMode(CENTER_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);

  pinMode(MOTOR_A_PWM, OUTPUT);
  pinMode(MOTOR_A_DIR, OUTPUT);
  pinMode(MOTOR_B_PWM, OUTPUT);
  pinMode(MOTOR_B_DIR, OUTPUT);

  stopMotors();
}

void loop() {
  bool left = digitalRead(LEFT_SENSOR);    
  bool center = digitalRead(CENTER_SENSOR);
  bool right = digitalRead(RIGHT_SENSOR);

  Serial.print("L: "); Serial.print(left);
  Serial.print(" C: "); Serial.print(center);
  Serial.print(" R: "); Serial.println(right);

  if (left == LOW && center == LOW && right == LOW) {
    stopMotors();
    searchline();  // never exits until line is found
  }
  else if (right == HIGH && center == LOW) {
    last_seen = 'R';
    turnRight();
  }
  else if (left == HIGH && center == LOW) {
    last_seen = 'L';
    turnLeft();
  }
  else if (right == HIGH) { // right + center both HIGH
    last_seen = 'R';
    moveForward();
  }
  else if (left == HIGH) {  // left + center both HIGH
    last_seen = 'L';
    moveForward();
  }
  else if (center == HIGH) {
    last_seen = 'C';
    moveForward();
  }
  else {
    stopMotors(); // fallback
  }

  delay(10);
}

// === Motion Functions ===

void moveForward() {
  digitalWrite(MOTOR_A_DIR, HIGH);
  digitalWrite(MOTOR_B_DIR, HIGH);
  analogWrite(MOTOR_A_PWM, fwd_speed);
  analogWrite(MOTOR_B_PWM, fwd_speed);
}

void turnLeft() {
  digitalWrite(MOTOR_A_DIR, LOW);
  digitalWrite(MOTOR_B_DIR, HIGH);
  analogWrite(MOTOR_A_PWM, turn_low);
  analogWrite(MOTOR_B_PWM, turn_high);
}

void turnRight() {
  digitalWrite(MOTOR_A_DIR, HIGH);
  digitalWrite(MOTOR_B_DIR, LOW);
  analogWrite(MOTOR_A_PWM, turn_high);
  analogWrite(MOTOR_B_PWM, turn_low);
}

void stopMotors() {
  analogWrite(MOTOR_A_PWM, 0);
  analogWrite(MOTOR_B_PWM, 0);
}

// === Search function ===

void searchline() {

  // Turn in direction of last seen line until any sensor detects black
  if (last_seen == 'R') {
    while (true) {
      turnRight();
      if (lineDetected()) {
        stopMotors();
        return;
      }
      delay(10);
    }
  } else {
    while (true) {
      turnLeft();
      if (lineDetected()) {
        stopMotors();
        return;
      }
      delay(10);
    }
  }
}

// === Line detection helper ===

bool lineDetected() {
  return digitalRead(CENTER_SENSOR) == HIGH ||
         digitalRead(LEFT_SENSOR) == HIGH ||
         digitalRead(RIGHT_SENSOR) == HIGH;
}
