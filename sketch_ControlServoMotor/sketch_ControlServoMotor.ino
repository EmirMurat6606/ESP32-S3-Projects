#include <Servo.h>

Servo myServo;
int servoPin = 3;
int analogIn = A0;
int readValue;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly: 
  readValue = analogRead(analogIn); // Value range 0 - 1023
  moveServo(readValue, 10);
  delay(10);
}

void moveServo(int analogValue, int analogRes){
  int maxVal = pow(2.0, analogRes) - 1;
  int angle = map(analogValue, 0, maxVal, 0, 180);
  myServo.write(angle);
}
