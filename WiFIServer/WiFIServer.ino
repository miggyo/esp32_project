#include <SoftwareSerial.h>

SoftwareSerial BTSerial(4, 3); // RX, TX

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600); // HC-06 초기화

  Serial.println("Ready to pair with HC-06");
}

void loop() {
  if (BTSerial.available()) {
    char data = BTSerial.read();
    Serial.print("Received from BT: ");
    Serial.println(data);
  }

  if (Serial.available()) {
    char data = Serial.read();
    BTSerial.write(data);/home/min/dev_ws/arduino/communication_MFC_arduino.py
    Serial.print("Sent to BT: ");
    Serial.println(data);
  }
}
