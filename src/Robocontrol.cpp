#include "Robocontrol.h"

#define IN1 5
#define IN2 6
#define IN3 11
#define IN4 10

Robocontrol::Robocontrol(uint8_t rxPin, uint8_t txPin) : mySerial(rxPin, txPin) {}

void Robocontrol::begin(long baudRate) {
  Serial.begin(115200);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  mySerial.begin(baudRate);
}

void Robocontrol::handleBluetooth() {
  while (mySerial.available()) {
    data = mySerial.read();
    Serial.print("Bluetooth Value: ");
    Serial.println(data);

    switch (data) {
      case 'F':
        Serial.println("Forward");
        forward();
        break;
      case 'B':
        Serial.println("Backward");
        backward();
        break;
      case 'L':
        Serial.println("Left");
        left();
        break;
      case 'R':
        Serial.println("Right");
        right();
        break;
      case 'S':
        Serial.println("Stop");
        stoprobot();
        break;
    }
  }
}

void Robocontrol::forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void Robocontrol::backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void Robocontrol::left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void Robocontrol::right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void Robocontrol::stoprobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
