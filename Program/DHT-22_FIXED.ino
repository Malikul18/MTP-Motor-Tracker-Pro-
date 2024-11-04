#define BLYNK_TEMPLATE_ID "TMPL667DMnRvl"
#define BLYNK_TEMPLATE_NAME "Kontrol relay"
#define BLYNK_AUTH_TOKEN "xYqn-lEY7k_U5ms9gfHdWRd1WVWdldYK"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

char auth[] = "xYqn-lEY7k_U5ms9gfHdWRd1WVWdldYK";
char ssid[] = "--ssidwifianda--";
char pass[] = "--passwifianda--";

#define DHTPIN 18         // Pin untuk DHT
#define DHTTYPE DHT22     // Tipe sensor DHT22
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

void setup(){
   Serial.begin(115200);
   Blynk.begin(auth, ssid, pass);
   dht.begin();
   timer.setInterval(5000L, sendSensor);  // Interval diperpanjang menjadi 5 detik
}

void loop(){
   Blynk.run();
   timer.run();
}

void sendSensor(){
   float h = 0;
   float t = 0;
   int samples = 5;

   // Membaca sensor beberapa kali untuk hasil yang lebih stabil
   Serial.println("Mengambil sampel data dari sensor...");
   for (int i = 0; i < samples; i++) {
      float humiditySample = dht.readHumidity();
      float temperatureSample = dht.readTemperature();
      
      // Menambahkan data sampel ke total
      h += humiditySample;
      t += temperatureSample;
      
      // Menampilkan setiap sampel pada Serial Monitor
      Serial.print("Sampel ");
      Serial.print(i + 1);
      Serial.print(" - Suhu: ");
      Serial.print(temperatureSample);
      Serial.print("°C, Kelembaban: ");
      Serial.print(humiditySample);
      Serial.println("%");
      
      delay(100); // jeda pendek antara pengukuran
   }

   // Menghitung rata-rata
   h /= samples;
   t /= samples;

   // Validasi hasil
   if (isnan(h) || isnan(t)) {
      Serial.println("Gagal membaca dari sensor DHT!");
      return;
   }

   // Mengirim data ke Blynk
   Blynk.virtualWrite(V8, h);
   Blynk.virtualWrite(V7, t);

   // Menampilkan hasil rata-rata di Serial Monitor
   Serial.println("Hasil Rata-rata:");
   Serial.print("Suhu: ");
   Serial.print(t);
   Serial.print("°C, Kelembaban: ");
   Serial.print(h);
   Serial.println("%");

   // Memeriksa suhu untuk logika alert
   if(t > 30){
      Serial.println("Peringatan: Suhu di atas 30°C!");
      Blynk.logEvent("temp_alert", "Temp above 30 degrees");
   }

   Serial.println("Data berhasil dikirim ke aplikasi Blynk.\n");
}
