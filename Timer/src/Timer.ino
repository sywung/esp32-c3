#include "hardware.h"
#include <Arduino.h>

volatile int A = 0;
volatile int B = 0;
volatile int C = 0;

volatile unsigned long queue[32];

portMUX_TYPE mux0 = portMUX_INITIALIZER_UNLOCKED;
portMUX_TYPE mux1 = portMUX_INITIALIZER_UNLOCKED;

volatile bool state = LOW;
hw_timer_t * timer0;   // 宣告硬體計時器物件指標
hw_timer_t * timer1;   // 宣告硬體計時器物件指標

void IRAM_ATTR onTimer0() { // 計時器0中斷服務常式 不能SERIAL
  portENTER_CRITICAL(&mux0); //要鎖住記憶體區塊,不然跑一跑就爆掉了

  A = A + 1;
  digitalWrite(BLED, digitalRead(BLED) ^ 1);

  portEXIT_CRITICAL(&mux0); //要鎖住記憶體區塊,不然跑一跑就爆掉了
}

void IRAM_ATTR onTimer1() { // 計時器1中斷服務常式 不能SERIAL
  portENTER_CRITICAL(&mux1); //要鎖住記憶體區塊,不然跑一跑就爆掉了

  B = B + 1;
  digitalWrite(WLED, digitalRead(WLED) ^ 1);

  portEXIT_CRITICAL(&mux1); //要鎖住記憶體區塊,不然跑一跑就爆掉了
}

void timerinit() {
   // 使用硬體計時器0建立0.5秒週期的計時器。
  timer0 = timerBegin(0, 80, true);
  timerAttachInterrupt(timer0, &onTimer0, true);
  timerAlarmWrite(timer0, 500000, true);//0.5S
  timerAlarmEnable(timer0);
  // 使用硬體計時器1建立1秒週期的計時器。
  timer1 = timerBegin(1, 80, true);
  timerAttachInterrupt(timer1, &onTimer1, true);
  timerAlarmWrite(timer1, 1000000, true);//1S
  timerAlarmEnable(timer1);
}

void setup() {
  Serial.begin(115200); 
  pinMode(BLED, OUTPUT);
  pinMode(WLED, OUTPUT);
  timerinit();
}

void loop() {
  Serial.print("A:");
  Serial.println(A);
  Serial.print("B:");
  Serial.println(B);
  Serial.print("C:");
  Serial.println(C);
  C = C+1 ;
  delay(500);
}

