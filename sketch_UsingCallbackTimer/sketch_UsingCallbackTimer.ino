#include <CBTimer.h>

const int ledPin = 13;

void callbackFunc(){
  int ledState = digitalRead(ledPin);
  digitalWrite(ledPin, !ledState);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("UNO Ready");

  pinMode(ledPin, OUTPUT);

  static CBTimer timer;  // Initialize a timer (static because only one instance can exist)
  timer.begin(1000, callbackFunc);
}

void loop() {
  // put your main code here, to run repeatedly:
  // EMPTY!!!
}
