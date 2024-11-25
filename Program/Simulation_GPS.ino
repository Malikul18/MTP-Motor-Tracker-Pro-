#define BLYNK_TEMPLATE_ID "TMPL667DMnRvl"
#define BLYNK_TEMPLATE_NAME "Kontrol relay"
#define BLYNK_AUTH_TOKEN "xYqn-lEY7k_U5ms9gfHdWRd1WVWdldYK"

#include <TinyGPS++.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#define BLYNK_PRINT Serial

// Pin RX dan TX untuk GPS
static const int RXPin = 17, TXPin = 16; // GPIO 16 = RX dan GPIO 17 = TX pada ESP32
static const uint32_t GPSBaud = 115200;

TinyGPSPlus gps; // Membuat objek TinyGPS++
WidgetMap myMap(V0);  // V0 untuk Virtual Pin dari Map Widget

HardwareSerial gpsSerial(2); // Menggunakan Serial2 untuk GPS (UART2 pada ESP32)

BlynkTimer timer;

float spd;       // Variabel untuk menyimpan kecepatan
float sats;      // Variabel untuk menyimpan jumlah satelit
String bearing;  // Variabel untuk menyimpan arah GPS

char auth[] = "xYqn-lEY7k_U5ms9gfHdWRd1WVWdldYK";  // Token autentikasi proyek
char ssid[] = "Redmi Note 11 Pro";                 // Nama jaringan
char pass[] = "gedegoblok";                        // Password jaringan

unsigned int move_index = 1; // Indeks lokasi (sementara tetap pada posisi tetap)

void setup()
{
  Serial.begin(115200);       // Untuk monitor serial
  Serial.println();
  gpsSerial.begin(GPSBaud, SERIAL_8N1, RXPin, TXPin); // Inisialisasi GPS pada Serial2
  Blynk.begin(auth, ssid, pass);  // Menghubungkan ke Blynk
  timer.setInterval(5000L, checkGPS); // Mengecek GPS setiap 5 detik
}

void checkGPS(){
  if (gps.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring."));
    Blynk.virtualWrite(V4, "GPS ERROR");  // Tampilkan error jika GPS tidak terdeteksi
  }
}

void loop()
{
  while (gpsSerial.available() > 0) 
  {
    // Menampilkan informasi setiap kali ada data baru dari GPS
    if (gps.encode(gpsSerial.read()))
      displayInfo();
  }
  Blynk.run();
  timer.run();
}

void displayInfo()
{ 
  if (gps.location.isValid()) 
  {    
    float latitude = gps.location.lat();     // Menyimpan Latitude dan Longitude
    float longitude = gps.location.lng(); 
    
    Serial.print("LAT:  ");
    Serial.println(latitude, 6);  // Tampilkan dengan 6 desimal
    Serial.print("LONG: ");
    Serial.println(longitude, 6);
    Blynk.virtualWrite(V1, String(latitude, 6));   
    Blynk.virtualWrite(V2, String(longitude, 6));  
    myMap.location(move_index, latitude, longitude, "GPS_Location");

    spd = gps.speed.kmph();               // Mendapatkan kecepatan
    Blynk.virtualWrite(V3, spd);

    sats = gps.satellites.value();         // Mendapatkan jumlah satelit
    Blynk.virtualWrite(V4, sats);

    bearing = TinyGPSPlus::cardinal(gps.course.value()); // Mendapatkan arah
    Blynk.virtualWrite(V5, bearing);                   
  }
  
  Serial.println();
}
