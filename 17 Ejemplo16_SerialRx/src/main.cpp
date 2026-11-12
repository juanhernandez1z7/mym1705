#include <Arduino.h>
#define Tx 17
#define Rx 16

#define b7 18
#define b6 26
#define b5 27
#define b4 33
#define b3 32
#define b2 13
#define b1 14
#define b0 4

uint8_t cuenta = 0;
uint8_t pin[8] = {b7, b6, b5, b4, b3, b2, b1, b0};
uint8_t estado[8] = {0, 0, 0, 0, 0, 0, 0, 0};

void mostrarDato();

void setup() {
  //Configuración de la UART
  Serial2.begin(115200, SERIAL_8N1, Rx, Tx);
  for(uint8_t i = 0; i<sizeof(pin)/sizeof(pin[0]); i++){
    pinMode(pin[i], OUTPUT);
  }
  Serial2.println(cuenta);
}

void loop() {
  delay(500);
  cuenta++;
  Serial2.println(cuenta);
  
 if(Serial2.available()>0){
  String dato = Serial2.readStringUntil('\n');
  cuenta = dato.toInt();
  mostrarDato();
 }
}

void mostrarDato(){
  
  uint8_t valor = cuenta;  
  //Limpiamos los valores de los estados 
  for(uint8_t i = 0; i<sizeof(estado)/sizeof(estado[0]); i++){
    estado[i] = 0;
  }
  uint8_t i = 1;
  uint8_t resultado = 0;
  uint8_t residuo = 0;
  while(valor>0){
    residuo = valor%2; //Obtenemos el residuo
    valor = valor/2; //obtenemos el valor de la división
    estado[8-i] = residuo;  
    i++;
  }
    //Mostramos los valores en los pines correspondientes
   for(uint8_t i = 0; i<sizeof(pin)/sizeof(pin[0]); i++){
    digitalWrite(pin[i], estado[i]);
  } 
}


