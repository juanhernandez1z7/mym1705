#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <Arduino_JSON.h>

#define LED1 25
#define LED2 26
#define LED3 27
#define LED4 32

const String ssid = "HC2";
const String pswd = "Juan150894";
const String url = "http://juanma.scienceontheweb.net/01LMYM/php/leer_led.php";


void setup() {
  pinMode(LED1, OUTPUT);  
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  Serial.begin(115200);
  Serial.print("Conectando");
  WiFi.begin(ssid, pswd);
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(200);
  }
  Serial.println("");
  Serial.print("Conectado a: ");
  Serial.println(ssid);
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());  
}


void loop() {
  if(WiFi.status() == WL_CONNECTED ){
    HTTPClient http;
    http.begin(url);
    int http_codigo = http.GET();

    if(http_codigo == 200){
      String datos = http.getString();
      JSONVar data = JSON.parse(datos);
      String led1_estado = data[0]["state"];
      String led2_estado = data[1]["state"];
      String led3_estado = data[2]["state"];
      String led4_estado = data[3]["state"];

      digitalWrite(LED1, led1_estado.toInt());
      digitalWrite(LED2, led2_estado.toInt());
      digitalWrite(LED3, led3_estado.toInt());
      digitalWrite(LED4, led4_estado.toInt());
    }

    http.end();
  }
  delay(500);
  
}
