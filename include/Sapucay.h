/*
  Sapucay.h - Libreria para ser usada en las lanzas de los bolsones.
*/
#ifndef Sapucay_h
#define Sapucay_h

#include <ESP8266WiFi.h>
#include <Arduino.h>

/*
* BME280 - Thanks adafruit for the lib
*/
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10
#define SEALEVELPRESSURE_HPA (1013.25)
/*
* Ends of BME280
*/


/*
* Configuracion de constantes
* WIFI_SSID             -- Nombre del SSID de la lanza maestro
* WIFI_PASSWORD         -- Password de la lanza maestro
* CHUCARO_IP            -- IP del servidor UDP
* CHUCARO_PORT          -- Puerto del servidor UDP
* SAPUCAY_USER_ID       -- ID del usuario
* SAPUCAY_PRODUCT       -- ID del producto
*/

// #define WIFI_SSID               "WIFI_CEGNET_07537"
// #define WIFI_PASSWORD           "d8ant@Co"
#define WIFI_SSID               "AndroidAP_7104"
#define WIFI_PASSWORD           "qweqweqwe"
#define CHUCARO_IP              "13.59.165.236"
#define CHUCARO_PORT            1234
#define SAPUCAY_USER_ID         "1"
#define SAPUCAY_PRODUCT         "silobags"


/*
* Sapucay class definition
*/
class Sapucay
{
    public:
        IPAddress str2IPAddress(String str);
        String makePkg(float temperature, float humidity);
        void sendSensorsData(float temperature, float humidity);
        void connectWiFi();
        int getIpBlock(int index, String str);
};

#endif