#include <Arduino.h>
#define pinPOT 25
#define pinPWM 27
#define pinINT 26

#define freq 1000
#define resolucion 8
#define canalPWM 0

uint8_t CT = 127;
volatile boolean bandera = false;

void IRAM_ATTR ISR_INT(){
  bandera= true;
}

void setup() {
  //Declaración de pines
  pinMode(pinPWM, OUTPUT);
  pinMode(pinINT, INPUT_PULLUP);
  
  //Configuración de PWM
  ledcSetup(canalPWM, freq, resolucion);
  ledcAttachPin(pinPWM, canalPWM);
  ledcWrite(canalPWM, CT);

  //Configuración de la Interrupción
  attachInterrupt(digitalPinToInterrupt(pinINT), ISR_INT, RISING);
}

void loop() {
  if(bandera){
    uint16_t lectura = analogRead(pinPOT);
    CT = map(lectura, 0, 4095, 0, 255);
    ledcWrite(canalPWM, CT);
    bandera = false;
  }
  
}
