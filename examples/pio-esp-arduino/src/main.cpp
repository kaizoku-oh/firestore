#include <Arduino.h>
#include "WiFi.h"

#include "wifi_config.h"

void connect_wifi(void) {
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println("Connected to the WiFi network");
}

void setup() {
  Serial.begin(115200);
  connect_wifi();
}

void loop() {
  // put your main code here, to run repeatedly:
}