#include <Arduino.h>

struct RGB {
  byte r;
  byte g;
  byte b;
};

const int PIN_R = 3;
const int PIN_G = 5;
const int PIN_B = 6;
const int DEBUG_LED = 13;

const RGB DEFAULT_COLOUR = {255, 255, 255};  // Colour to show before colour changed from command

int timeout = 0;

void display(RGB colour) {
  analogWrite(PIN_R, colour.r);
  analogWrite(PIN_G, colour.g);
  analogWrite(PIN_B, colour.b);
}

void setup() {
  Serial.begin(9600);
  pinMode(DEBUG_LED, OUTPUT);
  pinMode(PIN_R, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_B, OUTPUT);
}

void loop() {
  digitalWrite(DEBUG_LED, HIGH);
  Serial.println("Delaying with " + String(timeout));
  delay(timeout);
  digitalWrite(DEBUG_LED, LOW);
  delay(timeout);
  timeout += 100;
}
