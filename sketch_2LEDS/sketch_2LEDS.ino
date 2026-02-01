#define yellow 4
#define blue 5

void setup() {
  // put your setup code here, to run once:
  pinMode(yellow, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  blink(yellow);
  blink(blue);
}

void blink(size_t nr){
  digitalWrite(nr, HIGH);
  delay(1000);
  digitalWrite(nr, LOW);
}

