#include <Arduino.h>
#define interrupcion1 25
#define interrupcion2 26
#define A 14
#define B 27
#define C 13

uint8_t LED[3] = {A, B, C};
uint8_t estados[3] = {0,0,0};

volatile int8_t cuenta = 0;

void ISR_Incrementa();
void ISR_Decrementa();
void mostrarCuenta(uint8_t valor);


void setup() {
  //Configuración de puertos
  pinMode(interrupcion1, INPUT_PULLDOWN);
  pinMode(interrupcion2, INPUT_PULLUP);

  for(uint8_t i = 0; i< sizeof(LED)/sizeof(LED[0]); i++){
    pinMode(LED[i], OUTPUT);
  }

  //Configuración de Interrupciones Externas
  attachInterrupt(digitalPinToInterrupt(interrupcion1), ISR_Incrementa,RISING);
  attachInterrupt(digitalPinToInterrupt(interrupcion2), ISR_Decrementa,FALLING);

}

void loop() {
  if(cuenta>7){
    cuenta = 0;
  }else if(cuenta<0){
    cuenta = 7;
  }
    mostrarCuenta(cuenta);  
}

void IRAM_ATTR ISR_Incrementa(){
  cuenta++;
}

void IRAM_ATTR ISR_Decrementa(){
  cuenta--;
}

void mostrarCuenta(uint8_t valor){
  switch(valor){
    case 0:
      estados[0] = 0;
      estados[1] = 0;
      estados[2] = 0;
    break;

    case 1:
      estados[0] = 0;
      estados[1] = 0;
      estados[2] = 1;
    break;

    case 2:
      estados[0] = 0;
      estados[1] = 1;
      estados[2] = 0;
    break;

    case 3:
      estados[0] = 0;
      estados[1] = 1;
      estados[2] = 1;
    break;

    case 4:
      estados[0] = 1;
      estados[1] = 0;
      estados[2] = 0;
    break;

    case 5:
      estados[0] = 1;
      estados[1] = 0;
      estados[2] = 1;
    break;

    case 6:
      estados[0] = 1;
      estados[1] = 1;
      estados[2] = 0;
    break;

    case 7:
      estados[0] = 1;
      estados[1] = 1;
      estados[2] = 1;
    break;

    default:
        estados[0] = 1;
        estados[1] = 1;
        estados[2] = 1;
    break;
  }

   for(uint8_t i = 0; i< sizeof(LED)/sizeof(LED[0]); i++){
    digitalWrite(LED[i], estados[i]);
  }

}
