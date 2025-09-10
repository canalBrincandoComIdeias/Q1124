#include <LM35.h>
#define pinSensor A0
#define pinRele 10

LM35 sensor(pinSensor);

void setup() {
  pinMode(pinRele, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (sensor.getTemp() > 28) {
    digitalWrite(pinRele, HIGH);
  } 
  
  if (sensor.getTemp() < 27) {
    digitalWrite(pinRele, LOW);
  }

  Serial.println(sensor.getTemp());
}