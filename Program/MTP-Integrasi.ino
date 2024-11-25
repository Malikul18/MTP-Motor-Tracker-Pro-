#define BLYNK_TEMPLATE_ID "TMPL667DMnRvl"
#define BLYNK_TEMPLATE_NAME "Kontrol relay"
#define BLYNK_AUTH_TOKEN "xYqn-lEY7k_U5ms9gfHdWRd1WVWdldYK"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <OneWire.h>
#include <DallasTemperature.h>

const int dataPin = 2;// Pin yang terhubung ke pin DATA DS18B20

OneWire oneWire(dataPin);// Membuat instance dari OneWire
DallasTemperature sensors(&oneWire);// Membuat instance dari DallasTemperature

#define relay 4
#define relay1 15
int SW_relay = 0;
int SW1_relay = 0;

BlynkTimer timer;

char auth[] = "xYqn-lEY7k_U5ms9gfHdWRd1WVWdldYK";
const char* ssid = "Redmi Note 11 Pro";
const char* pass = "gedegoblok";

void setup() {
  Blynk.begin(auth, ssid, pass);
  // Memulai komunikasi serial
  Serial.begin(9600);

  // Memulai sensor DS18B20
  sensors.begin();
  pinMode(relay, OUTPUT);
  pinMode(relay1, OUTPUT);
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
  Blynk.virtualWrite(V7, temperatureC);

  delay(1000); // Membaca suhu setiap 1 detik
  Blynk.run();
  timer.run();
}

BLYNK_WRITE(V0)
{
  SW_relay = param.asInt();
  if (SW_relay == 1){
    digitalWrite(relay, HIGH);
    //Serial.println("Relay terbuka");
    Blynk.virtualWrite(V0, HIGH);
  }else{
    digitalWrite(relay, LOW);
    //Serial.println("Relay tertutup");
    Blynk.virtualWrite(V0, LOW);
  }
}
BLYNK_WRITE(V6)
{
  SW1_relay = param.asInt();
  if (SW1_relay == 1){
    digitalWrite(relay1, HIGH);
    //Serial.println("Relay1 terbuka");
    Blynk.virtualWrite(V6, HIGH);
  }else{
    digitalWrite(relay1, LOW);
    //Serial.println("Relay1 tertutup");
    Blynk.virtualWrite(V6, LOW);
  }
}
