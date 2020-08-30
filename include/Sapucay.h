/*
  Sapucay.h - Libreria para ser usada en las lanzas de los bolsones.
*/
#ifndef Sapucay_h
#define Sapucay_h

#include <ESP8266WiFi.h>
#include <Arduino.h>

/*
* Configuracion de constantes
* WIFI_SSID             -- Nombre del SSID de la lanza maestro
* WIFI_PASSWORD         -- Password de la lanza maestro
* CHUCARO_IP            -- IP del servidor UDP
* CHUCARO_PORT          -- Puerto del servidor UDP
* SAPUCAY_USER_ID       -- ID del usuario
* SAPUCAY_PRODUCT       -- ID del producto
*/

#define WIFI_SSID               "WIFI_CEGNET_07537"
#define WIFI_PASSWORD           "d8ant@Co"
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