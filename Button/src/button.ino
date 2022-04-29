#include "hardware.h"
#include <Arduino.h>

void setup() {
  // setup設定，只執行一次
  pinMode(OLED, OUTPUT);
  pinMode(WLED, OUTPUT);
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(115200);
}

int buttonState = 0;

void button2led() {
  buttonState = digitalRead(BUTTON);
  if (buttonState != HIGH) {
    // turn LED on
    if (digitalRead(GLED) == LOW) {
      digitalWrite(GLED, HIGH);
      Serial.println("Button pressed");
    }
  } else {
    // turn LED off
    if (digitalRead(GLED) == HIGH) {
      digitalWrite(GLED, !digitalRead(GLED));
      Serial.println("Button released");
    }
  }
}

void loop() { 
  button2led(); 
}
