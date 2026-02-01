#define Voltage_Offset -0.48


int B = 3950, R = 10, T1 = 25; // Known parameters
int analogInput = A0;

// Unknown parameters
float T2;
float Rt; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int readValue = analogRead(analogInput);

  float v = readValue * (5.0 / 1024); // Convert the analog read value to a voltage

  Rt = 10 * v / (5 - v); // Calculate the resistance value of the thermistor

  T2 = 1 / (1 / (273.15 + T1) + (log(Rt / R) / B)) - 273.15; // Degrees Celsius

  Serial.print(T2);
  delay(5000);
}
