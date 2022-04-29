#include "hardware.h"
#include <Arduino.h>

void setup() {
  // setup設定，只執行一次
  pinMode(OLED, OUTPUT);
  pinMode(WLED, OUTPUT);
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
  Serial.begin(115200);
}

void lOnp() { 
  blink(); 
}

void blink() {
  digitalWrite(WLED, HIGH); //開啟白燈
  Serial.println("WLED On");
  delay(500);              //休息0.5秒
  digitalWrite(WLED, LOW); //關閉白燈
  Serial.println("WLED Off");
  delay(500); //休息0.5秒

  digitalWrite(OLED, HIGH); //開啟橙燈
  Serial.println("OLED On");
  delay(500);              //休息0.5秒
  digitalWrite(OLED, LOW); //關閉橙燈
  Serial.println("OLED Off");
  delay(500); //休息0.5秒

  digitalWrite(RLED, HIGH); //開啟紅燈
  Serial.println("RLED On");
  delay(500);              //休息0.5秒
  digitalWrite(RLED, LOW); //關閉紅燈
  Serial.println("RLED Off");
  delay(500); //休息0.5秒

  digitalWrite(GLED, HIGH); //開啟綠燈
  Serial.println("GLED On");
  delay(500);              //休息0.5秒
  digitalWrite(GLED, LOW); //關閉綠燈
  Serial.println("GLED Off");
  delay(500); //休息0.5秒

  digitalWrite(BLED, HIGH); //開啟藍燈
  Serial.println("BLED On");
  delay(500);              //休息0.5秒
  digitalWrite(BLED, LOW); //關閉藍燈
  Serial.println("BLED Off");
  delay(500); //休息0.5秒
}
