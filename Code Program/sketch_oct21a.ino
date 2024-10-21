#include <TinyGPS++.h>
#include <HardwareSerial.h>

// Inisialisasi GPS
TinyGPSPlus gps;

// Menggunakan UART1 ESP32 (GPIO16 = RX, GPIO17 = TX)
HardwareSerial SerialGPS(1);

void setup() {
  // Serial Monitor untuk debug
  Serial.begin(115200);
  // Serial GPS (baud rate biasanya 9600 untuk modul GPS)
  SerialGPS.begin(9600, SERIAL_8N1, 16, 17);

  Serial.println("GPS Simulation with ESP32");
}

void loop() {
  // Membaca data dari GPS
  while (SerialGPS.available() > 0) {
    gps.encode(SerialGPS.read());
  }

  // Jika ada data GPS yang valid
  if (gps.location.isValid()) {
    Serial.print("Latitude: ");
    Serial.println(gps.location.lat(), 6);
    Serial.print("Longitude: ");
    Serial.println(gps.location.lng(), 6);
  } else {
    Serial.println("Mencari sinyal GPS...");
  }

  // Menampilkan waktu jika tersedia
  if (gps.time.isValid()) {
    Serial.print("Waktu GPS: ");
    Serial.print(gps.time.hour());
    Serial.print(":");
    Serial.print(gps.time.minute());
    Serial.print(":");
    Serial.println(gps.time.second());
  } else {
    Serial.println("Waktu GPS tidak tersedia.");
  }

  // Menunggu sebelum loop selanjutnya
  delay(1000);
}