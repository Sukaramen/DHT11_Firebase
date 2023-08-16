#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>
#include <DHT.h>


//................SSID DAN PASS PADA WIFI................//
const char* ssid = "*********";
const char* pass = "*********";

//................HOST DAN TOKEN PADA FIREBASE................//
#define FIREBASE_HOST "*********"
#define FIREBASE_TOKEN "*********"

FirebaseData DHTData;

#define DHTTYPE DHT11 //Sensor DHT yang dipakai
#define DHTPIN D2 //pin DHT yang dipakai
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(115200);
  Serial.println();
  dht.begin();
  WiFi.begin(ssid, pass);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(100);
    Serial.println("Tunggu.");
  }
  Serial.println();
  Serial.print("IP : ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_TOKEN);
  Firebase.reconnectWiFi(true);
}
void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  Serial.print("Temperature : ");
  Serial.print(t);
  Serial.println("C");
  Serial.print("Humidity : ");
  Serial.print(H);
  Serial.println("%"); 
  Firebase.setFloat(TestData, "/data/send", t); //Path pada database Firebase contoh /data/send
  Firebase.setFloat(TestData, "/data/send", h); //Path pada database Firebase contoh /data/send
}
