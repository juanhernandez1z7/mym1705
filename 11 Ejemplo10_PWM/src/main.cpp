#include <Arduino.h>
#define pinPWM 25
#define freq 1000
#define canalPWM 0
#define resolucion 8

void setup() {
  //Configuración de puertos
  pinMode(pinPWM, OUTPUT);

  //Configuración del PWM
  ledcSetup(canalPWM, freq,resolucion);
  ledcAttachPin(pinPWM, canalPWM);
}

void loop() {
  for(uint8_t i = 0; i<=255; i=i+5){
     ledcWrite(canalPWM, i);
     delay(20);
  } 

  for(uint8_t i = 255; i>0; i=i-5){
     ledcWrite(canalPWM, i);
     delay(20);
  }
}

