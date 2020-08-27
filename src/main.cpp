#include <Arduino.h>
#include <HTU21D.h>
#include <ESP8266WiFi.h>
#include "ESPAsyncUDP.h"
#include "SapucaySettings.h"


/**
 * Function to connect to WiFi.
 * In case of errors will log at the Serial Port.
 */
void connectToWifi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  int8_t wifiConnectStatus;
  
  while( (wifiConnectStatus = WiFi.waitForConnectResult(WIFI_CONNECT_TIMEOUT)) != WL_CONNECTED ) {
    switch (wifiConnectStatus)
    {
    case WL_CONNECT_FAILED: 
      Serial.println("Connection failed.");
      break;
    case WL_CONNECTION_LOST: 
      Serial.println("Connection lost.");
      break;
    case WL_DISCONNECTED: 
      Serial.println("Disconnected.");
      break;
    case WL_IDLE_STATUS: 
      Serial.println("Idle status.");
      break;
    case WL_CONNECTED: 
      Serial.println("Connected!.");
      break;
    default:
      break;
    }
    delay(1000);
  }
}


/**
 * Makes a package to be sent to Chucaro UDP Server.
 * @param      temp - Temperature given as a float
 * @param      hum  - Humidity given as a float
 * @return     A String type. A message. 
 */
String makePkg (float temp, float hum) {
  char pkg[9] = {0};
  sprintf(
    pkg,
    "%s:%s:%s:%s:%s",
    SAPUCAY_USER_ID,
    SAPUCAY_PRODUCT,
    system_get_chip_id(),
    temp,
    hum
    );
  return String(pkg);
}


/**
 * Send a package to Chucaro UDP Server.
 * @param      temp - Temperature given as a float
 * @param      hum  - Humidity given as a float
 */
void sendToChucaro(float temperature, float humidity) {
  String pkg = makePkg(temperature, humidity);
  AsyncUDP udp;
  if (udp.connect(CHUCARO_IP, CHUCARO_PORT))
  {
    udp.print(pkg);
    Serial.println("package sent");
    Serial.println(pkg);
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println();

  connectToWifi(); 
  while(true) {
    sendToChucaro(2, 3);
    delay(3000);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}