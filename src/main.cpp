#include <Arduino.h>
#include <HTU21D.h>
#include <ESP8266WiFi.h>
#include "Sapucay.h"

Sapucay sapucay;

void setup() {
  Serial.begin(115200);
  Serial.println();

  Serial.println("Conectando al wifi");
  sapucay.poronga();
}

void loop() {

  while (true)
  {
    Serial.println("Mandando data");
    sapucay.sendSensorsData(2.0, 3.0);
    delay(3000);
  }
  
}