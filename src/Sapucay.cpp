#include "Arduino.h"
#include "Sapucay.h"
#include "ESPAsyncUDP.h"


/**
 * Function to connect to WiFi.
 * In case of errors will log at the Serial Port.
 */
void Sapucay::connectWiFi() {
  Serial.println();
  delay(1000);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("Conectando");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Conectado, dirección IP: ");
  Serial.println(WiFi.localIP());

}


/**
 * Makes a package to be sent to Chucaro UDP Server.
 * @param      temp - Temperature given as a float
 * @param      hum  - Humidity given as a float
 * @return     A String type. A message. 
 */
String Sapucay::makePkg (float temp, float hum) {
  char pkg[9] = {0};
  const char *msgFormat = "%s:%s:%d:%f:%f";
  sprintf(
    pkg,
    msgFormat,
    SAPUCAY_USER_ID,
    SAPUCAY_PRODUCT,
    system_get_chip_id(),
    temp,
    hum
    );
  return String(pkg);
}

/**
 * Send sensors data Chucaro UDP Server.
 * @param      temperature - Temperature given as a float
 * @param      humimdity   - Humidity given as a float
 */
void Sapucay::sendSensorsData(float temperature, float humidity) {
  String pkg = makePkg(temperature, humidity);
  AsyncUDP udp;

  if (udp.connect(str2IPAddress(CHUCARO_IP), CHUCARO_PORT))
  {
    udp.print(pkg);
    Serial.println("package sent");
    Serial.println(pkg);
  }
}

/**
 * Converts a string ip address to an IPAddress instance.
 * @param      str - string ip address 
 * @return     IPAddress (Arduino) instance 
 */
IPAddress Sapucay::str2IPAddress(String str)
{
    IPAddress ip( getIpBlock(0,str),getIpBlock(1,str),getIpBlock(2,str),getIpBlock(3,str) );
    return ip;
}

int Sapucay::getIpBlock(int index, String str)
{
    char separator = '.';
    int found = 0;
    int strIndex[] = {0, -1};
    int maxIndex = str.length()-1;
  
    for(int i=0; i<=maxIndex && found<=index; i++){
      if(str.charAt(i)==separator || i==maxIndex){
          found++;
          strIndex[0] = strIndex[1]+1;
          strIndex[1] = (i == maxIndex) ? i+1 : i;
      }
    }
    
    return found>index ? str.substring(strIndex[0], strIndex[1]).toInt() : 0;

}

