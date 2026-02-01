const int input1 = 9, input2 = 10, pwm = 11;

int receivedValue;
unsigned int rotationSpeed;
bool rotationDir = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  pinMode(pwm, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  receivedValue = analogRead(A0);

  rotationSpeed = abs(receivedValue - 512);

  if (receivedValue > 512)
    rotationDir = true;
  else
    rotationDir = false;

  driveMotor(rotationDir, rotationSpeed);
}

void driveMotor(const bool dir, const unsigned int speed){

  if (dir){
    digitalWrite(input2, LOW);
    digitalWrite(input1, HIGH);
  }else{
    digitalWrite(input1, LOW);
    digitalWrite(input2, HIGH);
  }
  analogWrite(pwm, map(speed, 0, 512, 0, 255));
}
