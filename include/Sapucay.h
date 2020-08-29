/*
  Sapucay.h - Libreria para ser usada en las lanzas de los bolsones.
*/
#ifndef Sapucay_h
#define Sapucay_h

#include <ESP8266WiFi.h>
#include <Arduino.h>

#define WIFI_SSID               "Campo"                     // SSID de la lanza maestro
#define WIFI_PASSWORD           "1234"                      // Password para conectarse a la lanza maestro
#define WIFI_CONNECT_TIMEOUT    5000                        // Timeout max al momento de tratar de conectarse a la lanza maestro
#define WIFI_RETRY_TIMEOUT      1000                        // 1 segundo 
#define CHUCARO_IP              "13.59.165.236"             // IP del Servidor UDP
#define CHUCARO_PORT            1234                        // Puerto del servidor UDP
#define SAPUCAY_USER_ID         "1"                         // ID del usuario
#define SAPUCAY_PRODUCT         "silobags"                  // ID del usuario

class Sapucay
{
    public:
        // Sapucay();
        IPAddress str2IPAddress(String str);
        String makePkg(float temperature, float humidity);
        void sendSensorsData(float temperature, float humidity);
        void connectWiFi();
        void poronga();
        int getIpBlock(int index, String str);
};

#endif