/*
  Keyboard.h - Library for 6x8 Toy Laptop Keyboard.
  Created by Johannes le Roux, December 2, 2014.
  Released into the public domain.
*/
#ifndef Keyboard_h
#define Keyboard_h

#include "Arduino.h"

class Keyboard
{
  public:
    Keyboard(int,int,int,int,int,int,int,int);
    char read();
    char getChar();
  private:
    int _reset;
    int _clock;
    int _pins[6];
    long _debounce;
    static unsigned char _mapping[6][9];
    void clock();
    void reset();
};
#endif
