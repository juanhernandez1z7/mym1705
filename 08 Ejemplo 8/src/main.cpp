#include <Arduino.h>
#define PIN_LED 25

volatile bool bandera = false;
bool estadoLED = false;

hw_timer_s *timer0 = NULL;

void IRAM_ATTR ISR_Timer0(){
  bandera = true;
}

void setup() {
  //Configuración de puertos
  pinMode(PIN_LED, OUTPUT);

  //Valor inicial
  digitalWrite(PIN_LED, estadoLED);

  //Configuración de T0
  timer0 = timerBegin(0, 80, true);
  timerAttachInterrupt(timer0, &ISR_Timer0, true);
  timerAlarmWrite(timer0, 1000000, true);
  timerAlarmEnable(timer0);
}

void loop() {
  if(bandera){
    estadoLED = !estadoLED;
    digitalWrite(PIN_LED, estadoLED);
    bandera = false;
  }
}
