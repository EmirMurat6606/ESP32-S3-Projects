
int ledPin = 11;
int input; // Stores the integer value received from the serial port

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("UNO Ready");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()){
    input = Serial.parseInt();
    Serial.print("Received number: ");
    Serial.println(input);
    analogWrite(ledPin, constrain(input, 0, 255));
  }
}
