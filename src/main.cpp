#include <Arduino.h>
#include <HTU21D.h>
#include <ESP8266WiFi.h>
#include "Sapucay.h"

Sapucay sapucay;

void setup() {
  Serial.begin(115200);
  sapucay.connectWiFi();
}

void loop() {

  while (true)
  {
    sapucay.sendSensorsData(2.0, 3.0);
    delay(3000);
  }
  
}