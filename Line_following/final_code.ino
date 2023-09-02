//motor driver l298n connetions
const int motor1PWM = 5; 
const int motor1A = 4;
const int motor1B = 3;   
const int motor2PWM = 6; 
const int motor2A = 8;   
const int motor2B = 9;   
//ir sensor pins
const int leftIRSensorPin = A0;
const int rightIRSensorPin = A1;
const int lineThreshold = 500;
enum BacktrackState { NONE, LEFT, RIGHT };
BacktrackState backtrack = NONE;

void setup() {
  Serial.begin(9600);
  pinMode(motor1PWM, OUTPUT);
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2PWM, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
  pinMode(leftIRSensorPin, INPUT);
  pinMode(rightIRSensorPin, INPUT);
}

void loop() {
  int leftIRValue = analogRead(leftIRSensorPin);
  int rightIRValue = analogRead(rightIRSensorPin);
  bool leftLine = (leftIRValue < lineThreshold);
  bool rightLine = (rightIRValue < lineThreshold);
  //to stay in the line
  if (leftLine && rightLine) {
    moveForward();
    backtrack = NONE;
  } else if (!leftLine && rightLine) {
    turnLeft();
    backtrack = RIGHT;
  } else if (leftLine && !rightLine) {
    turnRight();
    backtrack = LEFT;
  } else {
    //bactrack
    switch (backtrack) {
      case LEFT:
        turnRight();
        break;
      case RIGHT:
        turnLeft();
        break;
      default:
        stopMotors();
    }
  }
}
//functions to move
void moveForward() {
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  analogWrite(motor1PWM, 255);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
  analogWrite(motor2PWM, 255); 
}
void turnLeft() {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  analogWrite(motor1PWM, 200); 
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
  analogWrite(motor2PWM, 200); 
}
void turnRight() {
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  analogWrite(motor1PWM, 200);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, HIGH);
  analogWrite(motor2PWM, 200); 
}
void stopMotors() {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, LOW);
}

