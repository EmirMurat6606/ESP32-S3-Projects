#include "TempAndHumidity.h"



void setup(){
  Serial.begin(115200);
  setup_dht();
}

void loop(){
  static unsigned long last = 0;
  if (millis() - last >= (MEASUREMENT_DELAY * 1000UL)) {
    last = millis();
    update_values();
  }
}