
const int led_amount = 10;
const int pins[10] =  {3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < led_amount; i++){
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  blinkEven();
  blinkOdd();
  blinkOutToIn();
}

void blinkOutToIn(){
  for(int i = 0; i < (led_amount/2); i++){
    digitalWrite(pins[i], HIGH);
    digitalWrite(pins[led_amount - 1 - i], HIGH);
    delay(1000);
    digitalWrite(pins[i], LOW);
    digitalWrite(pins[led_amount - 1 - i], LOW);
  }
}

void blinkOdd(){ 
  for(int i = 0; i < led_amount; i += 2){
    digitalWrite(pins[i], HIGH);
    delay(500);
  }

  for(int i = 0; i < led_amount; i += 2){
    digitalWrite(pins[i], LOW);
  }

}

void blinkEven(){
  for(int i = 1; i < led_amount; i += 2){
    digitalWrite(pins[i], HIGH);
    delay(500);
  }

  for(int i = 1; i < led_amount; i += 2){
    digitalWrite(pins[i], LOW);
  }
}
