#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#define pinSensor A0
#define pinRele 10

DHT_Unified sensor(pinSensor, DHT22);

void setup() {
  pinMode(pinRele, OUTPUT);
  sensor.begin();
  Serial.begin(9600);
}

void loop() {
  sensors_event_t event;
  sensor.temperature().getEvent(&event);

  if (event.temperature > 29) {
    digitalWrite(pinRele, HIGH);
  }

  if (event.temperature < 28) {
    digitalWrite(pinRele, LOW);
  }

  Serial.println(event.temperature);
}