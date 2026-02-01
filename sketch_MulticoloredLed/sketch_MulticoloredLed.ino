int ledR = 9, ledG = 10, ledB = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(ledR, random(256));
  analogWrite(ledG, random(256));
  analogWrite(ledB, random(256));
  delay(500);
}
