#ifndef IO_H
#define IO_H

#include <stdint.h>
#include "Arduino.h"

#define FC0   0
#define FC1   4
#define FC2   5
#define FC3  16
#define BA   12
#define BC   14
#define LED1  8
#define LED2  9
#define LED3  10

#define DLYBTN    100

class IO {

  private :
    bool valorPin(int pin);

  public :
    IO();
    void configIO(void);
    bool getArriba(void);
    bool getAbajo(void);
    bool getFinCarrera0(void);
    bool getFinCarrera1(void);
    bool getFinCarrera2(void);
    bool getFinCarrera3(void);
    void setLed(int num,bool cmd);

};



#endif
