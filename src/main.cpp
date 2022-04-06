#include <Arduino.h>
#include <WiFi.h>
#include <esp_wpa2.h> //wpa2 library for connections to Enterprise networks
#include "Credentials.h"

const char *ssid = WPA2_SSID;
const char *password = WPA2_PASSWORD;
const char *identity = WPA2_EAP_IDENTITY;

uint8_t ConnectWiFi(void);

void setup() {
  Serial.begin(115200);
  ConnectWiFi();
}

void loop() {
   // put your main code here, to run repeatedly:
}


uint8_t ConnectWiFi(void){
  WiFi.disconnect(true);  //disconnect from wifi to set new wifi connection
  WiFi.mode(WIFI_STA); //init wifi mode as station (normal WiFi client)
  esp_wifi_sta_wpa2_ent_set_identity((uint8_t *)identity, strlen(identity)); //provide identity
  esp_wifi_sta_wpa2_ent_set_username((uint8_t *)identity, strlen(identity)); //provide username --> identity and username is same
  esp_wifi_sta_wpa2_ent_set_password((uint8_t *)password, strlen(password)); //provide password

  esp_wpa2_config_t config = WPA2_CONFIG_INIT_DEFAULT();
  esp_wifi_sta_wpa2_ent_enable(&config);
  
  WiFi.begin(ssid); //connect to wifi
  uint8_t counter = 0;

  Serial.print("\n\nConnecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    counter++;
    if (counter >= 60) { //after 30 seconds timeout - reset board
      ESP.restart();
    }
  }
  Serial.printf("\nWiFi connected to \"%s\" (WPA2-Enterprise), with IP: ", ssid);
  Serial.println(WiFi.localIP()); //print LAN IP

  return 1;
}