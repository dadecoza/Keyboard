/*
  Keyboard.cpp - Library for 6x8 Toy Laptop Keyboard.
  Created by Johannes le Roux, December 2, 2014.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Keyboard.h"

unsigned char Keyboard::_mapping[8][6] = {
      {52 ,82 ,68,67 ,42 ,42},
      {51 ,69 ,83,88 ,32 ,42},
      {53 ,84 ,70,86 ,13,42},
      {49 ,81 ,42,104,27,8},
      {56 ,73 ,74,77 ,57 ,48},
      {50 ,87 ,65,90 ,42 ,42},
      {54 ,89 ,71,66 ,75 ,76},
      {55 ,85 ,72,78 ,79 ,80}
};

Keyboard::Keyboard(int reset,int clock, int row1, int row2,int row3,int row4, int row5, int row6)
{
  pinMode(reset,OUTPUT);
  pinMode(clock,OUTPUT);
  pinMode(row1,INPUT);
  pinMode(row2,INPUT);
  pinMode(row3,INPUT);
  pinMode(row4,INPUT);
  pinMode(row5,INPUT);
  pinMode(row6,INPUT);
  
  _reset = reset;
  _clock = clock;
  _pins[0] = row1;
  _pins[1] = row2;
  _pins[2] = row3;
  _pins[3] = row4;
  _pins[4] = row5;
  _pins[5] = row6;
 }
 
 char Keyboard::read() {
    reset();
    for (int i=0;i<8;i++) {
        for (int n=0;n<6;n++) {
            int c = digitalRead(_pins[n]);
            if (c == 1) {
                return _mapping[i][n];
            }
        }
        clock();
    }
    return NULL;
 }
 
 char Keyboard::getChar() {
    char c;
    do {
        c = read();
    } while (c == NULL);
    delay(150);
    return c;
 }
 
 void Keyboard::clock() {
  digitalWrite(_clock,HIGH);
  delay(1);
  digitalWrite(_clock,LOW);
}
 
void Keyboard::reset() {
  digitalWrite(_reset,HIGH);
  delay(1);
  digitalWrite(_reset,LOW);
}

