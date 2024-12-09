#include "WiFi.h"
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

#define GPS_TX_PIN 34 
#define GPS_RX_PIN 35 

TinyGPSPlus gps;
SoftwareSerial gpsSerial(GPS_RX_PIN, GPS_TX_PIN);

void setup() {
    Serial.begin(115200); // Soros monitor inicializálása
    gpsSerial.begin(9600); // GPS soros port beállítása
    delay(1000);

    // WiFi scanner inicializálása
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);
}

void loop() {
    // GPS adat kiolvasása
    while (gpsSerial.available() > 0) {
        if (gps.encode(gpsSerial.read())) {
            if (gps.location.isValid()) {
                Serial.print("GPS Latitude: ");
                Serial.println(gps.location.lat(), 6);
                Serial.print("GPS Longitude: ");
                Serial.println(gps.location.lng(), 6);
            } else {
                Serial.println("GPS data not valid.");
            }
        }
    }

    // WiFi hálózatok keresése
    int numNetworks = WiFi.scanNetworks();
    if (numNetworks == 0) {
        Serial.println("No WiFi networks found.");
    } else {
        Serial.printf("Found %d WiFi networks:\n", numNetworks);
        for (int i = 0; i < numNetworks; ++i) {
            Serial.printf("SSID: %s, RSSI: %d dBm, Channel: %d\n", 
                          WiFi.SSID(i).c_str(), 
                          WiFi.RSSI(i), 
                          WiFi.channel(i));
        }
    }

    delay(5000); // 5 másodperces frissítési idő
}
