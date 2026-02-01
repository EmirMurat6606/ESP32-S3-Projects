
const int pin1 = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  smoothBlink(pin1, 10);
}


void smoothBlink(const int pinNumber, const unsigned long changeDelay){

  for (int i = 0; i <= 100; i++){
    analogWrite(pinNumber, map(i, 0, 100, 0, 255));
    delay(changeDelay);
  }
  
  for(int i = 100; i >= 0; i--){
    analogWrite(pinNumber, map(i, 0, 100, 0, 255));
    delay(changeDelay);
  }
}