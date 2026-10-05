#include <Arduino.h>
#define x 26
#define y 27
#define z 25
#define A 33
#define B 34

bool leer_x = 0;
bool leer_y = 0;
bool leer_A = 0;
bool leer_B = 0;
bool salida = 0;

void setup() {
  //Configuración de puertos
  pinMode(x, INPUT_PULLUP);
  pinMode(y, INPUT_PULLUP);
  pinMode(A, INPUT_PULLUP);
  pinMode(B, INPUT_PULLUP);
  pinMode(z, OUTPUT);
  }

void loop() {
  //Lectura de A y B
  leer_A = digitalRead(A);
  leer_B = digitalRead(B);
  leer_x = digitalRead(x);
  leer_y = digitalRead(y);

  bool res = 0;
  if(leer_A == false && leer_B == false){
    res = leer_x & leer_y; //AND
  }else if(leer_A == false && leer_B == true){
    res = leer_x | leer_y; //OR
  } else if(leer_A == true && leer_B == false){
    res = !leer_x; //NOT
  } else {
    res = leer_x ^ leer_y;
  }

  digitalWrite(z, res);

}

