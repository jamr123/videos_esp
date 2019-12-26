#include "Motores.h"


Motores::Motores() {


}

void Motores::motoresConfig(void) {

  pinMode(STEPPIN, OUTPUT);
  pinMode(DIRPIN, OUTPUT);
  pinMode(ENPIN, OUTPUT);
  digitalWrite(ENPIN, LOW);


}
void Motores::direccionArriba(void) {
  digitalWrite(DIRPIN, HIGH); 

  for (int x = 0; x < 200; x++) {
    digitalWrite(STEPPIN, HIGH);
    delayMicroseconds(500);
    digitalWrite(DIRPIN, LOW);
    delayMicroseconds(500);
  }
}
void Motores::direccionAbajo(void) {
  digitalWrite(DIRPIN, LOW);

  for (int x = 0; x < 200; x++) {
    digitalWrite(STEPPIN, HIGH);
    delayMicroseconds(500);
    digitalWrite(DIRPIN, LOW);
    delayMicroseconds(500);
  }
}
