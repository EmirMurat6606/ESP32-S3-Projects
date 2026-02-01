const int inputPin = 12, outputPin = 9;

int outputState = LOW;
bool pressing = false;

void setup() {
  pinMode(inputPin, INPUT);
  pinMode(outputPin, OUTPUT);
}
void loop() {
  // Check if the periodic callback has been triggered
  if (digitalRead(inputPin) == LOW){
    if(!pressing){
      delay(10);
      if (digitalRead(inputPin) == LOW){
        pressing = true;
        outputState = !outputState;
      }
    }
  }else{
    pressing = false;
  }
  digitalWrite(outputPin, outputState);
}
