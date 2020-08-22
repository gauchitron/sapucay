#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "ESPAsyncUDP.h"
#include <Wire.h>
#include <HTU21D.h>

const char *ssid = "Campo";
const char *password = "mora2222";
const IPAddress server = IPAddress(13, 59, 165, 236); //13.59.165.236
const s16_t port = 1234;

char *userID = "2";
char *product = "silobags";
char *ChipID = "227498";

unsigned long TiempoAnterior_1 = 0;
const unsigned long intervalo_1 = 1000*10; //intervalo de sensor temperatura y humedad

// sensor temperatura y humedad
AsyncUDP udp;
HTU21D myHTU21D(HTU21D_RES_RH12_TEMP14);

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Wire.begin();
  
  while (myHTU21D.begin() != true)
  {
    Serial.println(F("HTU21D, SHT21 sensor is faild or not connected")); //(F()) saves string to flash & keeps dynamic memory free
    delay(5000);
  }
  Serial.println(F("HTU21D, SHT21 sensor is active"));
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED)
  {
    Serial.println("WiFi Failed");
    while (1)
    {
      delay(1000);
    }
  }
   if (udp.connect(server, port))
  {
    Serial.println("UDP connected");
  }
}

void loop()
{
  unsigned long TiempoActual_1 = millis();
  if ((unsigned long)(TiempoActual_1 - TiempoAnterior_1) >= intervalo_1){
    Serial.println(F("DEMO 1: 12-Bit Resolution"));
    Serial.print(F("Humidity............: ")); Serial.print(myHTU21D.readHumidity());            Serial.println(F(" +-2%"));
    Serial.println(F("DEMO 1: 14-Bit Resolution")); 
    Serial.print(F("Temperature.........: ")); Serial.print(myHTU21D.readTemperature()); Serial.println(F(" +-0.3C"));
    Serial.println("");
    
    char Temperatura[6];
    char Humedad[6];
    dtostrf ((myHTU21D.readTemperature()), 4, 2, Temperatura);
    dtostrf ((myHTU21D.readHumidity()), 4, 2, Humedad);

    Serial.print ("Temperatura: "); Serial.println (Temperatura);
    Serial.print ("Humedad: "); Serial.println (Humedad);
    Serial.println ("");
    Serial.println ("");

     //char *paquete=("%s,%s,%s,%s,%s",userID,product,ChipID,Temperatura,Humedad);

    //Serial.print ("prueba: "); Serial.println (paquete);
    //udp.print ("%s,%s,%s,%s,%s",userID,product,ChipID,Temperatura,Humedad);

    TiempoAnterior_1=TiempoActual_1;
    
    //char *pp=("%s,%s,%s,%s,%s",userID,product,ChipID,myHTU21D.readTemperature(),myHTU21D.readHumidity());
    //String stringOne = String(userID : ":silobags:227498:2:50:PP");
    //udp.print (stringOne);
    }
   
}

