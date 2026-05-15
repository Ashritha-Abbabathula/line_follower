// ----------- PINS -----------
const int leftIR  = A0;
const int rightIR = A5;

const int ENA = 13;
const int IN1 = 8;
const int IN2 = 7;

const int ENB = 12;
const int IN3 = 6;
const int IN4 = 4;

const int IR_THRESHOLD = 500;

const int BASE_SPEED  = 100;
const int TURN_SPEED  = 110;

int lastTurn = 0; // -1 = left, 0 = straight, 1 = right

// =============================================
void setup() {
  Serial.begin(9600);

  pinMode(leftIR,  INPUT);
  pinMode(rightIR, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopMotors();
  delay(2000);
  Serial.println("Starting line follow...");
}

// =============================================
void loop() {
  int leftVal  = analogRead(leftIR);
  int rightVal = analogRead(rightIR);

  bool leftOnLine  = (leftVal  > IR_THRESHOLD);
  bool rightOnLine = (rightVal > IR_THRESHOLD);

  Serial.print("L="); Serial.print(leftVal);
  Serial.print(" R="); Serial.print(rightVal);
  Serial.print(" | "); Serial.print(leftOnLine  ? "ON " : "off");
  Serial.print(" | "); Serial.println(rightOnLine ? "ON " : "off");

  if (leftOnLine && rightOnLine) {
    // Both on line → go straight
    lastTurn = 0;
    setMotors(BASE_SPEED, BASE_SPEED);
    moveForward();
  }
  else if (leftOnLine && !rightOnLine) {
    // Line to the left → sharp left: stop left motor, full right
    lastTurn = -1;
    analogWrite(ENA, 0);
    analogWrite(ENB, TURN_SPEED);
    turnLeft();
  }
  else if (!leftOnLine && rightOnLine) {
    // Line to the right → sharp right: stop right motor, full left
    lastTurn = 1;
    analogWrite(ENA, TURN_SPEED);
    analogWrite(ENB, 0);
    turnRight();
  }
  else {
    // Lost the line → continue last known direction to recover
    setMotors(TURN_SPEED, TURN_SPEED);
    if (lastTurn == -1)     turnLeft();
    else if (lastTurn == 1) turnRight();
    else                    moveForward();
  }
}

// =============================================
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMotors() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void setMotors(int speedA, int speedB) {
  analogWrite(ENA, speedA);
  analogWrite(ENB, speedB);
}
