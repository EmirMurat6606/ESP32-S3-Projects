int buzzerPin = 9;
float sinVal;
int freq;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int x = 0; x < 365; x++){
    sinVal = sin(x * (PI/180)); // Calculate the sinus value of x converted to radians
    freq = 2000 + sinVal * 500; // Tone function 
    tone(buzzerPin, freq);
    delay(1);
  }
}
