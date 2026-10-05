#include <Arduino.h>
#define entrada 26

uint8_t cuenta = 0;


void setup() {
  //Configuración de puertos
  pinMode(entrada, INPUT_PULLDOWN);
  //Inicializar comunicación Serial 
  Serial.begin(115200);
  Serial.println("¡Hola Mundo!");  
}

void loop() {
  //Leer valor en GPIO26
  bool lectura = digitalRead(entrada);

  if(lectura){
    cuenta++; //cuenta = cuenta+1;
    Serial.print("cuenta: ");
    Serial.println(cuenta);
    delay(250);
  }
 
}

