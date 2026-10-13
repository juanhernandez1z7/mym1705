#include <Arduino.h>
#define A 15
#define B 16
#define INT_500 25
#define INT_1000 26

volatile bool banderaTiempo = false;
volatile uint16_t retardo = 250;
uint8_t cuenta = 0;

hw_timer_s *timer0 = NULL;

void IRAM_ATTR ISR_500ms(){
  retardo = 500;
}

void IRAM_ATTR ISR_1000ms(){
  retardo = 1000;
}

void IRAM_ATTR ISR_T0(){
  timerAlarmWrite(timer0, retardo*1000, true);
  timerAlarmEnable(timer0);
  banderaTiempo = true;

}

void mostrarCuenta();


void setup() {
  //Configuración de puertos
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(INT_1000, INPUT_PULLUP);
  pinMode(INT_500, INPUT_PULLUP);

  //Configuración de Interrupciones Externas
  attachInterrupt(digitalPinToInterrupt(INT_500), ISR_500ms,RISING);
  attachInterrupt(digitalPinToInterrupt(INT_1000), ISR_1000ms,RISING);


  //Configuración de T0
  timer0 = timerBegin(0, 80, true);
  timerAttachInterrupt(timer0, &ISR_T0, true);
  timerAlarmWrite(timer0, 250000, true);
  timerAlarmEnable(timer0);

  //Muestra el valor inicial
  mostrarCuenta();
}

void loop() {
 if(banderaTiempo){
    if(cuenta>3){
      cuenta = 0;
    }else{
      cuenta++;
    }
    mostrarCuenta();
    banderaTiempo = false;    
 }
}

void mostrarCuenta(){
  switch (cuenta){ 
    case 0: 
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
    break;

    case 1: 
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
    break;

    case 2: 
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
    break;

    case 3: 
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
    break;

    default: 
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
    break;
  }
}
