#include <Arduino.h>

uint8_t LED = 25;

void setup() {
  //El GPIO25 configurado como salida
    pinMode(LED, OUTPUT); 
}

void loop() {
  //Se pone en alto GPIO25
  digitalWrite(LED, HIGH);
  //retardo = 500 ms
  delay(500);
   //Se pone en bajo GPIO25
  digitalWrite(LED, LOW);
  //retardo = 500 ms📆
  delay(500);
}

