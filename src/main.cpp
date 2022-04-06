#include <Arduino.h>
#include <WiFi.h>
#include "Credentials.h"

  #include <esp_wpa2.h> //wpa2 library for connections to Enterprise networks
    const char *ssid = WPA2_SSID;
    const char *password = WPA2_PASSWORD;
    const char *identity = WPA2_EAP_IDENTITY;

void setup() {
  // put your setup code here, to run once:
}

void loop() {
   // put your main code here, to run repeatedly:
}