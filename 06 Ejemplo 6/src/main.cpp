#include <Arduino.h>
#define pinInterrupcion 25

volatile bool bandera = false;
uint8_t cuenta = 0;

void ISR_G25();

void setup() {
  //Configuración de puertos
  pinMode(pinInterrupcion, INPUT_PULLDOWN);
  //Inicializar Comunicación Serial
  Serial.begin(115200);
  //Configurar Interrupciones Externas
  attachInterrupt(digitalPinToInterrupt(pinInterrupcion), ISR_G25, RISING);

}

void loop() {
  if(bandera){
    cuenta++; //cuenta = cuenta + 1
    Serial.print("Cuenta: ");
    Serial.println(cuenta);
    bandera = false;
  }  
}

void ISR_G25(){
  bandera = true;
}
