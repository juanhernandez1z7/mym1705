#include <Arduino.h>
#define entrada 33
#define salida  25
void setup(){
  pinMode(entrada, INPUT_PULLUP);
  pinMode(salida, OUTPUT);
}

void loop(){
  bool lectura = digitalRead(entrada);
  digitalWrite(salida, lectura);
}
