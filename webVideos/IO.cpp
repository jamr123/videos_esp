#include "IO.h"


IO::IO() {}



void IO::configIO(void) {

  pinMode(FC0, INPUT_PULLUP);
  pinMode(FC1, INPUT_PULLUP);
  pinMode(FC2, INPUT_PULLUP);
  pinMode(FC3, INPUT_PULLUP);
  pinMode(BA, INPUT_PULLUP);
  pinMode(BC, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

bool IO::getArriba(void) {
  return valorPin(BA);
}

bool IO::getAbajo(void) {
  return valorPin(BC);
}

bool IO::getFinCarrera0(void) {
  return valorPin(FC0);
}

bool IO::getFinCarrera1(void) {
  return valorPin(FC1);
}

bool IO::getFinCarrera2(void) {
  return valorPin(FC2);

}

bool IO::getFinCarrera3(void) {
  return valorPin(FC3);
}


bool IO::valorPin(int pin) {

  if (digitalRead(pin) == false) {
    delay(DLYBTN);
    if (digitalRead(pin) == false) {
      return true ;
    }
    else {
      return false;
    }
  }
  else {
    return false;
  }

}

void IO::setLed(int num,bool cmd){
  
   switch(num){
     case 1:
        digitalWrite(LED1,cmd);
        break;
     case 2:
        digitalWrite(LED2,cmd);
        break;
    case 3:
        digitalWrite(LED3,cmd);
        break;
    
    }
  
  }
