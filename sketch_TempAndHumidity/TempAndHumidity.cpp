#include "TempAndHumidity.h"


DHT_Unified dht(DHTPIN, DHTTYPE);

Measurement measurements[AMOUNT_OF_READINGS];

volatile float average_temp = 0;

volatile float average_hum = 0;

size_t idx = 0;


void setup_dht() {
  Serial.println("Setup DHT");
  dht.begin();
  sensor_t sensor;

  // Set delay between sensor readings based on sensor details.
  dht.humidity().getSensor(&sensor);
  dht.temperature().getSensor(&sensor);
}

void update_values() {
  // put your main code here, to run repeatedly:

  // Get temperature event and print its value.
  sensors_event_t event;

  float temp = NAN;
  float hum = NAN;

  // Get temperature event
  dht.temperature().getEvent(&event);
  if (!isnan(event.temperature))
    temp = event.temperature;

  // Get humidity event
  dht.humidity().getEvent(&event);
  if (!isnan(event.relative_humidity))
    hum = event.relative_humidity;

  measurements[idx].temp = temp;
  measurements[idx].hum = hum;
  average_results();

  idx = (idx + 1) % AMOUNT_OF_READINGS;
}

void average_results() {
  float t = 0, h = 0;
  int count = 0;

  for (int i = 0; i < AMOUNT_OF_READINGS; i++) {
    if (!isnan(measurements[i].temp)) {
      t += measurements[i].temp;
      h += measurements[i].hum;
      count++;
    }
  }

  if (count > 0) {
    average_temp = t / count;
    average_hum = h / count;
  }
}