
const int readingPin = 12, writingPin = 9;

bool isLighting = false; // variable to save the state of the led

void setup() {
  // put your setup code here, to run once:
  pinMode(readingPin, INPUT);
  pinMode(writingPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(readingPin) == LOW){
    delay(10); // Delay for a certain time to skip the bounce (Tutorial.pdf p.63 information)
    if(digitalRead(readingPin) == LOW){
      reverseLed();
      while(digitalRead(readingPin) == LOW){
        delay(10);
      }
    }
  }
}

void reverseLed(){
  if(isLighting){
    digitalWrite(writingPin, LOW);
    isLighting = false;
  }else{
    digitalWrite(writingPin, HIGH);
    isLighting = true;
  }
}