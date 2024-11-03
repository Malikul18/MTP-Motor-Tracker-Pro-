// Definisikan pin relay
#define RELAY1 7  // Relay pertama terhubung ke pin digital 7
#define RELAY2 8  // Relay kedua terhubung ke pin digital 8

void setup() {
  // Atur pin relay sebagai output
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);

  // Matikan kedua relay pada awalnya
  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);

  // Mulai komunikasi Serial untuk kontrol melalui Serial Monitor
  Serial.begin(9600);
  Serial.println("Relay Ready to go !");
  Serial.println("Ketik ON1 untuk menghidupkan Relay 1, OFF1 untuk mematikan");
  Serial.println("Ketik ON2 untuk menghidupkan Relay 2, OFF2 untuk mematikan");
}

void loop() {
  // Cek jika ada data di Serial Monitor
  if (Serial.available() > 0) {
    // Baca data dari Serial Monitor
    String command = Serial.readStringUntil('\n');
    command.trim();  // Menghapus spasi di awal/akhir jika ada

    // Cek perintah untuk Relay 1
    if (command == "ON1") {
      digitalWrite(RELAY1, LOW);  // Hidupkan Relay 1 (aktif LOW)
      Serial.println("Relay 1 ON");
    }
    else if (command == "OFF1") {
      digitalWrite(RELAY1, HIGH); // Matikan Relay 1
      Serial.println("Relay 1 OFF");
    }

    // Cek perintah untuk Relay 2
    else if (command == "ON2") {
      digitalWrite(RELAY2, LOW);  // Hidupkan Relay 2
      Serial.println("Relay 2 ON");
    }
    else if (command == "OFF2") {
      digitalWrite(RELAY2, HIGH); // Matikan Relay 2
      Serial.println("Relay 2 OFF");
    }
    else {
      Serial.println("Perintah tidak dikenal. Gunakan ON1, OFF1, ON2, atau OFF2.");
    }
  }
}
