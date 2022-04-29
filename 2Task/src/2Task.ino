#include "hardware.h"
#include <Arduino.h>
TaskHandle_t Task1;
TaskHandle_t Task2;

void setup() {
  Serial.begin(115200); 
  pinMode(GLED, OUTPUT);
  pinMode(RLED, OUTPUT);

  //create a task that will be executed in the Task1code() function, with priority 1 and executed on core 0
  xTaskCreatePinnedToCore(
                    Task1code,   /* Task function. */
                    "Task1",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &Task1,      /* Task handle to keep track of created task */
                    0);          /* pin task to core 0 */                  
  // delay(500); 

  // create a task that will be executed in the Task2code() function, with priority 1 and executed on core 1
  xTaskCreatePinnedToCore(
                    Task2code,   /* Task function. */
                    "Task2",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &Task2,      /* Task handle to keep track of created task */
                    0);          /* pin task to core 0 */
    // delay(500); 
}

void loop() {

}

//Task1code: blinks an LED every 1000 ms
void Task1code( void * pvParameters ){
  Serial.print("Task1 running on core ");
  Serial.println(xPortGetCoreID());

  for(;;){
    digitalWrite(GLED, HIGH);
    delay(1000);
    digitalWrite(GLED, LOW);
    delay(1000);
    Serial.print("Task1 running on core ");
    Serial.println(xPortGetCoreID());
  } 
}

//Task2code: blinks an LED every 700 ms
void Task2code( void * pvParameters ){
  Serial.print("Task2 running on core ");
  Serial.println(xPortGetCoreID());

  for(;;){
    digitalWrite(RLED, HIGH);
    delay(700);
    digitalWrite(RLED, LOW);
    delay(700);
    Serial.print("Task2 running on core ");
    Serial.println(xPortGetCoreID());
  }
}