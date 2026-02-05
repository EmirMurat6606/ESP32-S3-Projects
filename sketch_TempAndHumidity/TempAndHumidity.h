#ifndef TEMP_AND_HUMIDITY_H
#define TEMP_AND_HUMIDITY_H

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 12
#define DHTTYPE DHT11
#define AVERAGE_INTERVAL 30
#define MEASUREMENT_DELAY 5
#define AMOUNT_OF_READINGS 6


struct Measurement {
  float temp;
  float hum;
};

extern DHT_Unified dht;
extern Measurement measurements[AMOUNT_OF_READINGS];
extern volatile float average_temp;
extern volatile float average_hum;

extern size_t idx;


void setup_dht();

void update_values();

void average_results();

#endif
