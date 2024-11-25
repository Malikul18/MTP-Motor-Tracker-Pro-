#define BLYNK_TEMPLATE_ID "TMPL667DMnRvl"
#define BLYNK_TEMPLATE_NAME "Kontrol relay"
#define BLYNK_AUTH_TOKEN "xYqn-lEY7k_U5ms9gfHdWRd1WVWdldYK"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

BlynkTimer timer;
#define relay 2
#define relay1 15
int SW_relay = 0;
int SW1_relay = 0;

char auth[] = "xYqn-lEY7k_U5ms9gfHdWRd1WVWdldYK";
const char* ssid = "Redmi Note 11 Pro";
const char* pass = "gedegoblok";

void setup() {
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
  pinMode(relay1, OUTPUT);
  Blynk.begin(auth, ssid, pass);
  Serial.println(("ESP32 - Relay MTP_Simulation"));
  Serial.println();
}

 void loop() {
  Blynk.run();
  timer.run();
}

BLYNK_WRITE(V0)
{
  SW_relay = param.asInt();
  if (SW_relay == 1){
    digitalWrite(relay, HIGH);
    Serial.println("Relay terbuka");
    Blynk.virtualWrite(V0, HIGH);
  }else{
    digitalWrite(relay, LOW);
    Serial.println("Relay tertutup");
    Blynk.virtualWrite(V0, LOW);
  }
}
BLYNK_WRITE(V6)
{
  SW1_relay = param.asInt();
  if (SW1_relay == 1){
    digitalWrite(relay1, HIGH);
    Serial.println("Relay1 terbuka");
    Blynk.virtualWrite(V6, HIGH);
  }else{
    digitalWrite(relay1, LOW);
    Serial.println("Relay1 tertutup");
    Blynk.virtualWrite(V6, LOW);
  }
}
