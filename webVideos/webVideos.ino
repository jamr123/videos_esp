#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "IO.h"
#include "Motores.h"


IO io;
Motores motores;

bool fc0 = 0;
bool fc1 = 0;
bool fc2 = 0;
bool fc3 = 0;
bool arriba = 0;
bool abajo = 0;

int nivel = 0;


void setup() {

  Serial.begin(115200);
  io.configIO();
  motores.motoresConfig();
  wifiConfig("INFINITUM0AAE", "JamrEjro135"); //SSID,PASSWORD
  posicionInicial();

}

void loop() {

  if (io.getArriba() == 1) {
    subirNivel();
  }

  if (io.getAbajo() == 1) {
    posicionInicial();
  }

}

void sendDato(String dato) {
   String jsonSend="{\"dato\":\""+dato+"\"}";
   if(WiFi.status()== WL_CONNECTED){  
 
   HTTPClient http;  
 
   http.begin("http://192.168.0.23:3333/api_v_01/dps");     
   http.addHeader("Content-Type", "application/json"); 
   
   int httpCode = http.POST(jsonSend);  
   String payload = http.getString();                
 
   Serial.println(httpCode);   
   Serial.println(payload);    
 
   http.end();
 
 }else{
 
    Serial.println("Error in WiFi connection");   
 
 }

}
void subirNivel() {

  switch (nivel) {
    case 0:
      sendDato("N1");
      Serial.println("poscicion Nivel1 BUSCANDO....");
      fc1 = io.getFinCarrera1();
      while (fc1 == 0) {
        motores.direccionArriba();
        fc1 = io.getFinCarrera1();
        delay(1);
      }
      sendDato("nivel1");
      Serial.println("poscicion nivel1 encontrado");
      nivel = 1;
      break;
    case 1:
      sendDato("N2");
      Serial.println("poscicion Nivel2 BUSCANDO....");
      fc2 = io.getFinCarrera2();
      while (fc2 == 0) {
        motores.direccionArriba();
        fc2 = io.getFinCarrera2();
        delay(1);
      }
      sendDato("nivel2");
      Serial.println("poscicion nivel2 encontrado");
      nivel = 2;
      break;
    case 2:
      sendDato("N3");
      Serial.println("poscicion Nivel3 BUSCANDO....");
      fc3 = io.getFinCarrera3();
      while (fc3 == 0) {
        motores.direccionArriba();
        fc3 = io.getFinCarrera3();
        delay(1);
      }
      sendDato("nivel3");
      Serial.println("poscicion nivel3 encontrado");
      nivel = 3;
      break;

  }

}
void posicionInicial() {
   sendDato("N0");
  Serial.println("poscicion abajo BUSCANDO....");
  fc0 = io.getFinCarrera0();
  while (fc0 == 0) {
    motores.direccionAbajo();
    fc0 = io.getFinCarrera0();
    delay(1);
  }
  sendDato("nivel0");
  Serial.println("poscicion abajo encontrada");
  nivel = 0;
}

void wifiConfig(char* ssid, char* password) {


  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("conectando");
  }
  Serial.println(WiFi.localIP());
  Serial.println("wifi conectado");
}
