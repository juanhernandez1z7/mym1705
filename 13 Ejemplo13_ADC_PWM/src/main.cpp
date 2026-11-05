#include <Arduino.h>
#define pinPotR 25
#define pinPotG 26
#define pinPotB 27

#define pinR 32
#define pinG 13
#define pinB 14

#define canalR 0
#define canalG 1
#define canalB 2

#define freq 1000
#define resolucion 8

uint16_t CTR = 0;
uint16_t CTG =  0;
uint16_t CTB = 0;

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
  CTR = analogRead(pinPotR);  
  CTG = analogRead(pinPotG);
  CTB = analogRead(pinPotB);
  
  CTR = map(CTR, 0, 4095, 0, 255);
  CTG = map(CTG, 0, 4095, 0, 255);
  CTB = map(CTB, 0, 4095, 0, 255);

  ledcWrite(canalR, CTR);
  ledcWrite(canalG, CTG);
  ledcWrite(canalB, CTB);

  delay(100);
  
}

