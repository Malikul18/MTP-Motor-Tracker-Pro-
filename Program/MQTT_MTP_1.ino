#include <WiFi.h>
#include <MQTT.h>

const char ssid[]       = "Username WiFi"; //SSID WIFI
const char pass[]       = "Password WiFi"; //PASSWORD WIFI
const char* mqtt_server = "broker.hivemq.com"; //MQTT Broker for HiveMQ
const char* client_id   = "Motor Tracker Pro"; // Unique client ID

WiFiClient net;
MQTTClient client;

String currentLatitude = "";
String currentLongitude = "";

unsigned long lastMillis = 0;

void connect() {
  Serial.print("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("Connecting to MQTT...");
  while (!client.connect(client_id)) {  // Leave username/password empty if unnecessary
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nConnected to MQTT broker!");

  // Subscribe to topics
  client.subscribe("ping/Motor Tracker Pro");  // Kodular can subscribe to this for updates
  client.subscribe("Motor Tracker Pro/relay1");
  client.subscribe("Motor Tracker Pro/relay2");
  client.subscribe("Motor Tracker Pro/latitude"); // Latitude from Kodular or GPS
  client.subscribe("Motor Tracker Pro/longitude"); // Longitude from Kodular or GPS
}

void messageReceived(String &topic, String &payload) {
  Serial.println("Topic: {" + topic + "} | Message: [" + payload + "]");

  // Relay control for integration with Kodular's control interface
  if (topic == "Motor Tracker Pro/relay1") {
    if (payload == "ON") Serial.println("RELAY1 ON");
    else if (payload == "OFF") Serial.println("RELAY1 OFF");
  }
  if (topic == "Motor Tracker Pro/relay2") {
    if (payload == "ON") Serial.println("RELAY2 ON");
    else if (payload == "OFF") Serial.println("RELAY2 OFF");
  }

  // Process latitude and longitude data
  if (topic == "Motor Tracker Pro/latitude") currentLatitude = payload;
  if (topic == "Motor Tracker Pro/longitude") currentLongitude = payload;

  // Display Google Maps link when both coordinates are received
  if (!currentLatitude.isEmpty() && !currentLongitude.isEmpty()) {
    String googleMapsUrl = "https://www.google.com/maps/search/?api=1&query=" + currentLatitude + "," + currentLongitude;
    Serial.println("Google Maps URL: " + googleMapsUrl);
  }
}

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, pass);

  client.begin(mqtt_server, net);
  client.onMessage(messageReceived);
  connect();
}

void loop() {
  client.loop();
  delay(10);  // Helps WiFi stability

  if (!client.connected()) {
    connect(); // Reconnect if connection is lost
  }

  // Publish a message every second to ping Kodular
  if (millis() - lastMillis > 1000) {
    lastMillis = millis();
    client.publish("ping/Motor Tracker Pro", "Hello This is MTP Project");
  }
}
