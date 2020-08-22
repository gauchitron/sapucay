#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "ESPAsyncUDP.h"
#include "TeroGlobalSettings.h"


void connectToWifi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  
  while( (WiFi.waitForConnectResult(WIFI_CONNECT_TIMEOUT)) != WL_CONNECTED ) {
    Serial.println("WiFi Failed");
    yield();
  }

}

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}