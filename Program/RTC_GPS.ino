#include <Wire.h>
#include <RTClib.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

// Inisialisasi objek RTC dan GPS
RTC_DS1307 rtc;
TinyGPSPlus gps;

// Pin untuk koneksi GPS dengan SoftwareSerial
SoftwareSerial gpsSerial(3, 4); // RX, TX untuk GPS

void setup() {
  Serial.begin(9600);       // Serial Monitor
  gpsSerial.begin(9600);    // Serial untuk GPS
  Wire.begin();             // I2C untuk RTC

  // Inisialisasi RTC
  if (!rtc.begin()) {
    Serial.println("RTC tidak ditemukan!");
    while (1);
  }

  // Cek apakah RTC berjalan, jika tidak atur waktu secara manual
  if (!rtc.isrunning()) {
    Serial.println("RTC tidak berjalan, mengatur waktu...");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));  // Atur waktu sesuai kompilasi program
  }

  Serial.println("Program RTC DS1307 dan GPS Neo-6M siap");
}

void loop() {
  // Pembacaan dari GPS
  while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());
  }

  // Tampilkan waktu RTC jika GPS tidak tersedia atau belum fix
  DateTime now = rtc.now();
  Serial.print("Waktu RTC: ");
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();

  // Jika data GPS valid, tampilkan waktu dan lokasi GPS
  if (gps.location.isValid() && gps.time.isValid()) {
    Serial.print("Waktu GPS: ");
    Serial.print(gps.time.hour());
    Serial.print(':');
    Serial.print(gps.time.minute());
    Serial.print(':');
    Serial.print(gps.time.second());
    Serial.println();

    Serial.print("Lokasi GPS: ");
    Serial.print("Latitude: ");
    Serial.print(gps.location.lat(), 6);
    Serial.print(", Longitude: ");
    Serial.println(gps.location.lng(), 6);
  } else {
    Serial.println("Data GPS belum tersedia atau tidak valid.");
  }

  // Jeda 1 detik sebelum pembacaan berikutnya
  delay(1000);
}
