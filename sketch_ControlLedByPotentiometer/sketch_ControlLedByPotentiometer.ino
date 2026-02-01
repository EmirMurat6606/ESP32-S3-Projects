int adcValueP1, adcValueP2, adcValueP3; // Define a variable to save ADC values of 3 potentiometers
int ledR = 9, ledG = 10, ledB = 11;

void setup() {
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);

  analogReadResolution(14);

}

void loop() {

  // Read the values of the potentiometers
  // Range between 0-16383
  adcValueP1 = analogRead(A3);
  adcValueP2 = analogRead(A4);
  adcValueP3 = analogRead(A5);

  analogWrite(ledR, map(adcValueP1, 0, 16383, 0, 255));
  analogWrite(ledG, map(adcValueP2, 0, 16383, 0, 255));
  analogWrite(ledB, map(adcValueP3, 0, 16383, 0, 255));
} 