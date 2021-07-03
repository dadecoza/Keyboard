/*
  Keyboard.cpp - Library for 6x8 Toy Laptop Keyboard.
  Created by Johannes le Roux, December 2, 2014.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Keyboard.h"

unsigned char Keyboard::_mapping[6][9] = {
      {'6', '7', '5', '2', 0, '8', '4', '3', '1'},
      {'Y', 'U', 'T', 'W', 0, 'I', 'R', 'E', 'Q'},
      {'G', 'H', 'F', 'A', 0, 'J', 'D', 'S',   0},
      {'B', 'N', 'V', 'Z', 0, 'M', 'C', 'X',   0},
      {'K', 'O',  13,   32, 0, '9',   0,   0,  27},
      {'L', 'P',   0,   8, 0, '0',   0,   0,   0}
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
  _debounce = 0;
 }
 
 char Keyboard::read() {
    if (_debounce > millis()) return NULL;
    reset();
    for (int i=0;i<9;i++) {
        for (int n=0;n<6;n++) {
            int c = digitalRead(_pins[n]);
            if (c == 1) {
                _debounce = millis()+100;
                return _mapping[n][i];
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

