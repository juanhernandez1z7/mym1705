#include <Arduino.h>
#define pinPot 25

uint16_t lectura = 0;

void setup() {
  //Inicializar Comunicación Serial
  Serial.begin(115200);
  Serial.print("¡Hola Mundo!");
  Serial.println("¡Adiós Mundo!");  
}

void loop() {
  lectura = analogRead(pinPot);
  Serial.print("Lectura: ");
  Serial.println(lectura);
  delay(100);  
}

