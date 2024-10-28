#define BLYNK_TEMPLATE_ID "TMPL667DMnRvl"
#define BLYNK_TEMPLATE_NAME "Kontrol relay"
#define BLYNK_AUTH_TOKEN "xYqn-lEY7k_U5ms9gfHdWRd1WVWdldYK"

#include <WiFi.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

//SensorDHT
#define DHTPIN 18
#define DHTTYPE DHT22
DHT dht (DHTPIN, DHTTYPE);

//SensorGPS-Neo6m
#define GPS_BAUDRATE 9600  
static const int RXPin = 4, TXPin = 5;
TinyGPSPlus gps; 
WidgetMap myMap(V7);  
SoftwareSerial ss(RXPin, TXPin);  

//Relay
#define relay 2
int SW_relay = 0;

BlynkTimer timer;

float spd;       //Variable  to store the speed
float sats;      //Variable to store no. of satellites response
String bearing;  //Variable to store orientation or direction of GPS

char auth[] = "xYqn-lEY7k_U5ms9gfHdWRd1WVWdldYK";
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

//unsigned int move_index;         // moving index, to be used later
unsigned int move_index = 1;       // fixed location for now

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

void setup() {
  Serial.begin(9600);
  pinMode(relay, OUTPUT);

  Serial.println("Motor Tracker Pro");
  Serial.println(F("ESP32 - GPS module_Simulation"));
  Serial.println();

  dht.begin();
  ss.begin(GPS_BAUDRATE);
  Serial2.begin(GPS_BAUDRATE);//serial2 for GPS UART
  timer.setInterval(5000L, checkGPS);
  Blynk.begin(auth, ssid, pass);
}

void checkGPS(){
  if (gps.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring."));
      Blynk.virtualWrite(V4, "GPS ERROR");  // Value Display widget  on V4 if GPS not detected
  }
}

void loop() {
  while (ss.available() > 0) 
    {
      // sketch displays information every time a new sentence is correctly encoded.
      if (gps.encode(ss.read()))
        displayInfo();
    }
  Blynk.run();
  timer.run();
}

void displayInfo()
{ 
  if (gps.location.isValid() ) 
  {    
    float latitude = (gps.location.lat());     //Storing the Lat. and Lon. 
    float longitude = (gps.location.lng()); 
    
    Serial.print("LAT:  ");
    Serial.println(latitude, 6);  // float to x decimal places
    Serial.print("LONG: ");
    Serial.println(longitude, 6);
    Blynk.virtualWrite(V1, String(latitude, 6));   
    Blynk.virtualWrite(V2, String(longitude, 6));  
    myMap.location(move_index, latitude, longitude, "GPS_Location");
    spd = gps.speed.kmph();               //get speed
       Blynk.virtualWrite(V3, spd);
       
       sats = gps.satellites.value();    //get number of satellites
       Blynk.virtualWrite(V4, sats);

       bearing = TinyGPSPlus::cardinal(gps.course.value()); // get the direction
       Blynk.virtualWrite(V5, bearing);                   
  }
  // put your main code here, to run repeatedly:
  float t = dht.readTemperature(); //menghitung suhu
  float h = dht.readHumidity(); //menghitung kelembaban
  delay(1000);

  Blynk.virtualWrite(V7, t); //mengirim data ke blynk
  Blynk.virtualWrite(V8, h);

  //Menampilkan data di serial monitor
  Serial.println("Suhu = ");;
  Serial.print(t);
  Serial.println("Kelembaban = ");;
  Serial.print(h);
  Serial.println();
  
 Serial.println();
}

