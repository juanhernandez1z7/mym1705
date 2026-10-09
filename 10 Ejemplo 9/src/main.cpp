#include <Arduino.h>
#define A 15
#define B 16
#define C 17
#define D 18

#define INT1 25
#define INT2 26

//definimos los vectores para los pines y estados 
uint8_t LED[4] = {A, B, C, D};
uint8_t estados[4] = {0, 0, 0, 0};
int8_t cuenta = 0;

uint8_t cuenta_max = 15;
uint8_t cuenta_min = 0;

volatile bool bandera_tiempo = false;
volatile bool bandera_retardo = true; //true->25000000, false-> 1000000

uint32_t retardo = 250000;



hw_timer_s *timer0 = NULL;

void mostrarCuenta();
void ISR_G25();
void ISR_G26();
void ISR_retardo();


void setup() {
    //Configuración de puertos
    for(uint8_t i = 0; i<sizeof(LED)/sizeof(LED[0]); i++){
        pinMode(LED[i], OUTPUT);
    }
    pinMode(INT1, INPUT_PULLUP);
    pinMode(INT2, INPUT_PULLUP);
    
    //Configuración de Interrupciones Externas
    attachInterrupt(digitalPinToInterrupt(INT1), ISR_G25, RISING);
    attachInterrupt(digitalPinToInterrupt(INT2), ISR_G26, FALLING);

    //Configuración de Interrupciones por timer0
    timer0 = timerBegin(0, 80, true);
    timerAttachInterrupt(timer0, &ISR_retardo, true);
    timerAlarmWrite(timer0, retardo, true);
    timerAlarmEnable(timer0);

    //Valor Inicial
    mostrarCuenta();
}

void loop() {
    if(bandera_tiempo){
      if(bandera_retardo){
        retardo = 250000;
      }else{
        retardo = 1000000;
      }
      cuenta++;
      if(cuenta>cuenta_max){
        cuenta = cuenta_min;
      }
        mostrarCuenta();        
        bandera_tiempo = false;
    }  
}

void IRAM_ATTR ISR_G25(){
    bandera_retardo = false;
}

void IRAM_ATTR ISR_G26(){
    bandera_retardo = true;
}

void IRAM_ATTR ISR_retardo(){
    timerAlarmWrite(timer0, retardo, true);
    timerAlarmEnable(timer0);
    bandera_tiempo = true;
}

void mostrarCuenta(){
    switch (cuenta){
        case 0:
            estados[3] = 0;             
            estados[2] = 0;
            estados[1] = 0;
            estados[0] = 0;
        break;
        case 1:
            estados[3] = 0; 
            estados[2] = 0;
            estados[1] = 0;
            estados[0] = 1;
        break;
        case 2: 
            estados[3] = 0;
            estados[2] = 0;
            estados[1] = 1;
            estados[0] = 0;
        break;
        case 3:
            estados[3] = 0; 
            estados[2] = 0;
            estados[1] = 1;
            estados[0] = 1;
        break;
        case 4:
            estados[3] = 0; 
            estados[2] = 1;
            estados[1] = 0;
            estados[0] = 0;
        break;
        case 5: 
            estados[3] = 0;
            estados[2] = 1;
            estados[1] = 0;
            estados[0] = 1;
        break;
        case 6: 
            estados[3] = 0;
            estados[2] = 1;
            estados[1] = 1;
            estados[0] = 0;
        break;
        case 7:
            estados[3] = 0; 
            estados[2] = 1;
            estados[1] = 1;
            estados[0] = 1;
        break;

        case 8:
            estados[3] = 1;             
            estados[2] = 0;
            estados[1] = 0;
            estados[0] = 0;
        break;
        case 9:
            estados[3] = 1; 
            estados[2] = 0;
            estados[1] = 0;
            estados[0] = 1;
        break;
        case 10: 
            estados[3] = 1;
            estados[2] = 0;
            estados[1] = 1;
            estados[0] = 0;
        break;
        case 11:
            estados[3] = 1; 
            estados[2] = 0;
            estados[1] = 1;
            estados[0] = 1;
        break;
        case 12:
            estados[3] = 1; 
            estados[2] = 1;
            estados[1] = 0;
            estados[0] = 0;
        break;
        case 13: 
            estados[3] = 1;
            estados[2] = 1;
            estados[1] = 0;
            estados[0] = 1;
        break;
        case 14: 
            estados[3] = 1;
            estados[2] = 1;
            estados[1] = 1;
            estados[0] = 0;
        break;
        case 15:
            estados[3] = 1; 
            estados[2] = 1;
            estados[1] = 1;
            estados[0] = 1;
        break;
        default:
            estados[3] = 0; 
            estados[2] = 0;
            estados[1] = 0;
            estados[0] = 0;
        break;
    }

    for(uint8_t i = 0; i<sizeof(LED)/sizeof(LED[0]); i++){
        digitalWrite(LED[i], estados[i]);
    }


}

