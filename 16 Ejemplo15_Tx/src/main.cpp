#include <Arduino.h>
#define Tx 17
#define Rx 16

uint8_t cuenta = 0;


void setup() {
  //Configuración de la UART
  Serial2.begin(115200, SERIAL_8N1, Rx, Tx);
  //valor Inicial
  Serial2.println(cuenta);
}

void loop() {
  delay(500);
  cuenta++;
  Serial2.println(cuenta);
}

