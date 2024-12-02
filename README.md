# Flyer MTP
<div align="center">
<img src = "Dokumentasi/flyer.png" width="500px">
  </div>
# MTP-Motor-TrackerPro-
<div align="center">
  <img src = "Asset/Logo MTP.jpeg" alt="LOGO" width="200px"/>
</div>

## Optimalisasi Operasional dengan Pelacakan Realtime dan Kesehatan Kendaraan Berbasis ESP32

MTP atau Motor Tracker Pro adalah perangkat pelacak motor canggih yang terhubung langsung dengan smartphone Anda, dirancang untuk memberikan kontrol dan pemantauan penuh terhadap kendaraan Anda. Fungsi utamanya adalah melacak lokasi motor secara real-time dan mencatat waktu setiap lokasi dikirimkan, sehingga Anda dapat memonitor pergerakan kendaraan dengan mudah.

Dengan teknologi IoT, aplikasi Motor Tracker Pro memungkinkan pengguna untuk menghidupkan motor dan mengunci starter secara cerdas melalui smartphone, memberikan kontrol penuh atas keamanan motor Anda kapan pun dibutuhkan. Selain itu, aplikasi ini menampilkan informasi lengkap tentang suhu dan kelembapan mesin, memungkinkan pengguna memantau kondisi mesin dan memastikan performa tetap optimal. Motor Tracker Pro memberikan pengalaman monitoring motor yang aman, praktis, dan terintegrasi.

## Manfaat
Motor Tracker Pro memberikan berbagai manfaat yang signifikan bagi penggunanya, terutama dalam hal keamanan dan kenyamanan. Berikut beberapa manfaat utama dari alat ini:

1. **Keamanan Motor yang Lebih Terjamin**  
   Dengan pelacakan lokasi real-time dan pemberitahuan waktu lokasi dikirim, Anda dapat memantau posisi motor kapan saja, mengurangi risiko pencurian. Fitur penguncian jarak jauh melalui aplikasi juga menambah lapisan keamanan ekstra.

2. **Pengoperasian Motor yang Lebih Mudah dan Fleksibel**  
   Fitur IoT memungkinkan Anda menghidupkan motor atau mengunci starter melalui smartphone. Manfaat ini berguna saat Anda ingin memanaskan motor dari jarak jauh atau mengunci motor dengan cepat jika terjadi hal yang mencurigakan.

3. **Pemantauan Kondisi Mesin untuk Perawatan yang Lebih Baik**  
   Informasi suhu dan kelembapan mesin yang ditampilkan di aplikasi membantu Anda memantau kondisi motor, sehingga Anda bisa mengetahui tanda-tanda awal jika ada masalah pada mesin, seperti potensi overheating atau kelembapan yang berlebihan, yang dapat memengaruhi performa.

4. **Efisiensi Waktu dan Praktis**  
   Dengan kendali motor yang ada di smartphone, Anda dapat mengakses motor kapan saja dan dari mana saja tanpa perlu berada di dekatnya. Ini sangat berguna untuk pengguna yang sering bepergian atau parkir di tempat umum.

5. **Pemantauan Rute dan Riwayat Lokasi**  
   Motor Tracker Pro membantu Anda melacak riwayat pergerakan motor, sehingga Anda dapat mengidentifikasi rute yang telah dilalui. Hal ini berguna untuk memantau penggunaan motor oleh orang lain atau mengetahui area mana yang lebih sering dilalui.

6. **Pengalaman Berkendara yang Lebih Tenang**  
   Dengan fitur keamanan dan monitoring yang lengkap, Anda dapat lebih tenang dan merasa aman saat meninggalkan motor di tempat parkir atau saat motor dipinjam oleh orang lain.

Motor Tracker Pro adalah solusi lengkap untuk pemantauan, keamanan, dan perawatan motor yang modern dan praktis, menjadikan kendaraan Anda lebih aman dan nyaman.

## Support By :
>- Dosen Pengampu : Akhmad Hendriawan ST., MT. (NIP.197501272002121003)
>- Mata kuliah : IoT dan Jaringan Sensor
>- Program Studi : D4 Teknik Elektronika
>- Politeknik Elektronika Negeri Surabaya<br>

## Team Member :
|      NRP      |       Nama      |    Jobdesk    |   Akun |
| :-----------:|:----------------:| :------------:| :-----:|
| 2122500038    | Malikul ula Al Farizi  | Project Manager       | [Malikul18] (https://github.com/Malikul18)
| 2122500041    | Tegar Bagus Aditya         |   Programmer  | [LEEEOOONNN] (https://github.com/LEEEOOONNN)
| 2122500047    | Aziza Octavia         |    UI/UX Designer      | [Azizaoct] (https://github.com/Azizaoct)
| 2122500049    | Dikri Sadam Panca Sakti                | Hardware | [DKRSDMPNCSKT] (https://github.com/DKRSDMPNCSKT)
| 2122500054    | Dwie Maulana Kalyana               | Data Analist     | [Dwiemaulana] (https://github.com/Dwiemaulana)

#Daftar Isi
- [Komponen](#Komponen)
- [Diagram Arsitektur Sistem](#Diagram-Arsitektur-Sistem)
- [Hardware](#Hardware)
- [Software](#Software)
- [Desain Prototype](#Desain-Prototype)
   * [Desain UI/UX MTP](#Desain-UI/UX-MTP)
- [Rincian Biaya](#Rincian-Biaya)

# Komponen
1. ESP32
2. Relay 2 Channel
3. Sensor GPS Neo-6M
4. RTC
5. DHT22
6. Module Step-Down

# Diagram Arsitektur Sistem
<div align="center">
<img src = "Dokumentasi/Blok Diagram MTP.png" width="500px">
  </div>
## Cara Kerja Motor Tracker Pro Secara Singkat**  
1. Pelacakan Lokasi Real-Time  
   - Perangkat ini dilengkapi modul GPS (seperti ublox NEO-6M) yang mendeteksi lokasi motor.  
   - Informasi lokasi dikirim ke Broker HiveMQ lalu dilanjutkan ke Kodular 
   - Data ini ditampilkan di aplikasi smartphone Anda dalam bentuk peta, sehingga Anda bisa memantau posisi motor kapan saja.  

2. Kontrol Motor via Smartphone  
   - Perangkat terhubung ke sistem starter motor melalui modul IoT.  
   - Dengan aplikasi, Anda bisa mengirim perintah untuk menghidupkan motor atau mengunci starter.  
   - Perintah dikirim melalui jaringan internet ke perangkat di motor, lalu dieksekusi secara otomatis.  

3. Pemantauan Suhu dan Kelembapan Mesin  
   - Sensor suhu dan kelembapan di perangkat membaca kondisi mesin motor.  
   - Data ini dikirimkan ke aplikasi, membantu Anda memantau performa mesin dan mendeteksi potensi masalah lebih awal.  

4. Riwayat Lokasi dan Pemberitahuan  
   - Sistem mencatat setiap lokasi yang dilalui motor dan menyimpannya di server.  
   - Anda bisa melihat riwayat pergerakan motor dan mendapatkan notifikasi saat motor berpindah tempat.  

5. Keamanan Tambahan  
   - Jika motor terdeteksi bergerak tanpa izin, Anda bisa segera mengunci starter melalui aplikasi.  
   - Lokasi motor yang terus dilacak memudahkan Anda menemukan kendaraan jika hilang.  

Hasilnya, dengan Motor Tracker Pro, Anda mendapatkan kontrol penuh dan real-time terhadap motor, baik untuk keamanan, kenyamanan, maupun perawatan mesin.
  
# Youtube MTP 
- Vidio iklan [Motor Tracker Pro](https://youtube.com/shorts/t2EillxIgAg?feature=share)

# Hardware
<div align="center">
<img src ="Asset/PCB MTP Layer Atas.jpg" width="500px">
</div>
<div align="center">
<img src ="Asset/PCB MTP Layer Bawah.jpg" width="500px">
</div>


# Software
## Pengujian Relay 2 Channel sebagai Kunci dan Starter Sepeda Motor
Program ini menggunakan *ESP32* untuk mengontrol dua relay melalui aplikasi *Blynk*. Relay adalah komponen elektronik yang berfungsi seperti saklar, yang bisa dikendalikan secara elektronik. Pada Projek ini Kontrol relay digunakan untuk menyalakan dan mematikan kunci dan starte sepeda motor menggunakan smartphone sebagai inovasi IoT dari salah satu fungsui MTP.Cara kerja program :
1. ESP32 terhubung ke Wi-Fi dan aplikasi Blynk.
2. Di aplikasi Blynk, pengguna mengontrol dua tombol virtual (V0 dan V1):
   - Tombol V0 mengontrol relay di pin 2.
   - Tombol V1 mengontrol relay di pin 15.
3. Saat tombol ditekan, relay menyala (membuka sirkuit).
4. Saat tombol dilepas, relay mati (menutup sirkuit).
5. Status relay dikembalikan ke aplikasi Blynk dan ditampilkan di Serial Monitor.

#define BLYNK_TEMPLATE_ID "TMPL6gpzdGcuz"
#define BLYNK_TEMPLATE_NAME "Kunci Relay"
#define BLYNK_AUTH_TOKEN "fu98OTmzLjvvY9Xmn6revk_N22ejEKPd"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

BlynkTimer timer;
#define relay 2
#define relay1 15
int SW_relay = 0;
int SW1_relay = 0;

char auth[] = "fu98OTmzLjvvY9Xmn6revk_N22ejEKPd";
const char* ssid = "--NamaSsidPerangkat--";
const char* pass = "--PassWiFi--";

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
BLYNK_WRITE(V1)
{
  SW1_relay = param.asInt();
  if (SW1_relay == 1){
    digitalWrite(relay1, HIGH);
    Serial.println("Relay1 terbuka");
    Blynk.virtualWrite(V1, HIGH);
  }else{
    digitalWrite(relay1, LOW);
    Serial.println("Relay1 tertutup");
    Blynk.virtualWrite(V1, LOW);
  }
}


## Pengujian Sensor DS18B20 untuk Memantau Suhu Mesin Sepeda Motor
Program ini adalah implementasi *IoT* menggunakan ESP32 untuk membaca suhu mesin sepeda motor dari sensor *DS18B20* dan mengirimkan serta menampilkan datanya ke aplikasi *Blynk*. Cara Kerja Program :
1. ESP32 terhubung ke Wi-Fi dan aplikasi Blynk.
2. DS18B20 membaca suhu secara berkala (setiap 1 detik).
3. Suhu yang terbaca:
   - Ditampilkan di *Serial Monitor* untuk debugging.
   - Dikirim ke aplikasi Blynk melalui *Virtual Pin V0*.
4. Di aplikasi Blynk, suhu dapat dimonitor secara real-time.

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
const char* pass = "--PassWiFI--";

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

# Desain Prototype
## Desain UI/UX MTP
Tampilan awal UI/UX MTP      |   
<img src = "Dokumentasi/home.png" width="250px"> | <img src = "Dokumentasi/Register blank.png" width="250px">| <img src = "Dokumentasi/Register.png" width="250px">
<img src = "Dokumentasi/Log in blank.png" width="250px"> | <img src = "Dokumentasi/Log in.png" width="250px">
- [Figma](https://www.figma.com/design/K79DKEpYAUl1oy9ZEVzn8G/Prototyping-in-Figma?node-id=0-1&node-type=canvas&t=O9agAbHADH6BsXUb-0)
- Prototype *MTP* menggunakan Figma untuk UI/UX adalah sebuah desain antarmuka interaktif yang bertujuan untuk memvisualisasikan konsep dan alur pengguna dari sebuah aplikasi atau sistem yang sedang dikembangkan. Prototipe ini memungkinkan pengguna atau pemangku kepentingan untuk memahami bagaimana aplikasi akan berfungsi, termasuk navigasi, tata letak, dan interaksi antar elemen di dalamnya. Dalam Figma, prototipe *MTP* dapat mencakup elemen-elemen seperti tombol, form input, menu, serta transisi antar halaman atau skenario pengguna.

# Rincian Biaya
| No  | Item                   | Jumlah | Harga   | Total   |
|-----|------------------------|--------|---------|---------|
| 1   | ESP32 Devkitc 32D      | 1      | 66.900  | 66.900  |
| 2   | 2 Channel Relay Module 5V/3.3V    | 1     | 15.000   | 15.000   |
| 3   | GPS Module Ublox NEO 6M V2          | 1      | 74.500     | 74.500     |
| 4   | Tinny RTC DS1307          | 1      | 10.000  | 10.000  |
| 5   | DHT22 Module Sensor      | 1      | 70.000     | 70.000     |
| 6   | Project Board Power Module      | 1      | 12.000   | 12.000   |
| 7   | 3D Print Casing        | -      | -  | -  |
|     |                        |        |         |         |
