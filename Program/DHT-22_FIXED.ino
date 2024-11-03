#include <DHT.h>

// Definisikan pin dan tipe sensor
#define DHTPIN 2       // Pin digital yang terhubung ke DHT-22
#define DHTTYPE DHT22  // Tipe sensor DHT22

// Inisialisasi sensor DHT
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT22 test!");
  dht.begin();
}

void loop() {
  // Beri jeda sensor untuk melakukan pembacaan (sekitar 2 detik)
  delay(2000);

  // Membaca kelembapan
  float humidity = dht.readHumidity();
  // Membaca suhu dalam Celcius
  float temperature = dht.readTemperature();
  // Membaca suhu dalam Fahrenheit
  float fahrenheit = dht.readTemperature(true);

  // Cek apakah pembacaan berhasil
  if (isnan(humidity) || isnan(temperature) || isnan(fahrenheit)) {
    Serial.println("Gagal membaca dari sensor DHT!");
    return;
  }

  // Menampilkan hasil ke Serial Monitor
  Serial.print("Kelembapan: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Suhu: ");
  Serial.print(temperature);
  Serial.print(" *C ");
  Serial.print(fahrenheit);
  Serial.println(" *F");
}
