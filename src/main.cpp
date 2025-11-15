#include <Arduino.h>
#include <AccelStepper.h>

const int JOY_X = A0;

const int DIR_PIN_2 = 10;
const int STEP_PIN_2 = 9;
const int EN_PIN_2 = 8;

const int SPEED = 400;

AccelStepper myStepper(AccelStepper::DRIVER, STEP_PIN_2, DIR_PIN_2);


// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(EN_PIN_2, OUTPUT);
  digitalWrite(EN_PIN_2, LOW); // Enable the stepper driver

  myStepper.setMaxSpeed(1000);
  myStepper.setAcceleration(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  int xVal = analogRead(JOY_X);
  int stepsToMove = map(xVal, 0, 1023, -SPEED, SPEED);
  myStepper.setSpeed(stepsToMove);
  myStepper.runSpeed();
}