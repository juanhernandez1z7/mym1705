//Diseñe un programa que genere 3 señales PWM (asociadas 
//a el color Rojo, Verde y Azul) con una frecuencia de 
//1 kHz, una resolucion de 8 bits. El ciclo de trabajo
//se asignará según los 3 colores que elija. 

#include <Arduino.h>
#define pinR 25
#define pinG 26
#define pinB 27

#define canalR 0
#define canalG 1
#define canalB 2

#define freq 1000
#define resolucion 8

void setup() {
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);
  
  ledcSetup(canalR, freq, resolucion);
  ledcSetup(canalG, freq, resolucion);
  ledcSetup(canalB, freq, resolucion);

  ledcAttachPin(pinR, canalR);
  ledcAttachPin(pinG, canalG);
  ledcAttachPin(pinB, canalB);
}

void loop() {
  ledcWrite(canalR,0);
  ledcWrite(canalG,0);
  ledcWrite(canalB,0);
  delay(250);
  
  ledcWrite(canalR, 255);
  ledcWrite(canalG, 0);
  ledcWrite(canalB, 0);
  delay(250);

  ledcWrite(canalR, 0);
  ledcWrite(canalG, 255);
  ledcWrite(canalB, 0);
  delay(250);

  ledcWrite(canalR, 0);
  ledcWrite(canalG, 0);
  ledcWrite(canalB, 255);
  delay(250);

  ledcWrite(canalR, 255);
  ledcWrite(canalG, 255);
  ledcWrite(canalB, 255);
  delay(250);

}

