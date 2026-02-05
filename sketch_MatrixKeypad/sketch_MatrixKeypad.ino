const byte buzzerPin = 3;
const byte ledPin = 13;
const byte ROWS = 4;
const byte COLS = 4;

const unsigned int countdown_time = 15;  // 15 seconds countdown time
const char secret_password[] = { '#', '1', '5', '9' };
unsigned int counter = 0;

byte rowPins[] = { 11, 10, 9, 8 };
byte colPins[] = { 7, 6, 5, 4 };

char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (byte r = 0; r < ROWS; r++) {
    pinMode(rowPins[r], OUTPUT);
    digitalWrite(rowPins[r], HIGH);
  }

  for (byte c = 0; c < COLS; c++) {
    pinMode(colPins[c], INPUT_PULLUP);
  }

  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  startCountDown(countdown_time);
  delay(30000);  // 30 seconds time-out
}

char getKey() {
  // Scan each row sequentially
  for (byte r = 0; r < ROWS; r++) {
    digitalWrite(rowPins[r], LOW);  // Activate current row
    for (byte c = 0; c < COLS; c++) {
      if (digitalRead(colPins[c]) == LOW) {  // Check if key is pressed (LOW)
        delay(20);                           // Debounce delay
        while (digitalRead(colPins[c]) == LOW)
          ;                              // Wait for key release
        digitalWrite(rowPins[r], HIGH);  // Deactivate current row
        return keys[r][c];               // Return corresponding key value
      }
    }
    digitalWrite(rowPins[r], HIGH);  // Deactivate current row
  }
  return '\0';  // No key pressed
}


void startCountDown(unsigned int seconds) {

  digitalWrite(ledPin, HIGH);

  unsigned long begin = millis();
  unsigned long time_now = millis();

  bool alarm_cooldown = true;
  bool alarm_on = false;

  while (alarm_cooldown) {
    char key = getKey();
    time_now = millis();

    if (!alarm_on && (time_now - begin) > seconds * 1000UL){
      digitalWrite(buzzerPin, HIGH);
      alarm_on = true;
    }

    if (key != '\0') {
      if (key == secret_password[counter]) {
        Serial.print("Pressed: ");
        Serial.println(key);
        counter++;
      } else {
        counter = 0;
        if(!alarm_on)
          digitalWrite(buzzerPin, HIGH);
      }
    }

    if (counter == 4) {
      counter = 0;
      alarm_cooldown = false;
    }
  }
  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);
}