#ifndef MOTORES_H
#define MOTORES_H
#include <stdint.h>
#include "Arduino.h"

#define STEPPIN   2
#define DIRPIN   13
#define ENPIN    15

class Motores {

  private :



  public :

    Motores();
    void motoresConfig(void);
    void direccionArriba(void);
    void direccionAbajo(void);


};


#endif
