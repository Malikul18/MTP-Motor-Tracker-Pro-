#define BLYNK_TEMPLATE_ID "TMPL6WFMyxSwG"
#define BLYNK_TEMPLATE_NAME "DS18B20Temperature"
#define BLYNK_AUTH_TOKEN "M0G-asq9c1-Qyj-I_5InTObtkUO7urGc"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <OneWire.h>
#include <DallasTemperature.h>

const int dataPin = 2;// Pin yang terhubung ke pin DATA DS18B20

OneWire oneWire(dataPin);// Membuat instance dari OneWire
DallasTemperature sensors(&oneWire);// Membuat instance dari DallasTemperature

BlynkTimer timer;

char auth[] = "M0G-asq9c1-Qyj-I_5InTObtkUO7urGc";
const char* ssid = "--NamaSsidPerangkat--";
const char* pass = "--PassWiFi--";

void setup() {
  Blynk.begin(auth, ssid, pass);
  // Memulai komunikasi serial
  Serial.begin(9600);

  // Memulai sensor DS18B20
  sensors.begin();
}

void loop() {
  // Meminta sensor untuk melakukan pembacaan suhu
  sensors.requestTemperatures();

  // Membaca suhu dalam Celsius dari sensor pertama (index 0)
  float temperatureC = sensors.getTempCByIndex(0);

  // Menampilkan suhu di Serial Monitor
  Serial.print("Suhu: ");
  Serial.print(temperatureC);
  Serial.println(" °C");
  Blynk.virtualWrite(V0, temperatureC);

  delay(1000); // Membaca suhu setiap 1 detik
  Blynk.run();
  timer.run();
}
