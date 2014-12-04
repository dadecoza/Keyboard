# Keyboard

![Keboard](https://dl.dropboxusercontent.com/s/8nrk4vs5pqrakeu/arduinolt2.jpg)

This is a library to use a toy / education laptop keyboard with Arduino.

The keyboard is 6 rows by 8 columns.

The 6 rows goes to 6 of the Arduinos io pins (with pull down resistors).

The 8 columns goes to a 4017 decade counter / johnson counter pins Q0 to Q7.

The Reset and Clock pins on the 4017 goes to Arduino io pins.

# install
Create a directory under your Arduino/libraries called "Keyboard"
Copy the Keyboard.cpp and Keyboard.h files to the directory.
Restart the Arduino IDE. 

#usage 
````Aeduino
#include <Keyboard.h>

//Decade Counter reset pin = Arduino pin 8
//Decade Counter clock pin = Arduino pin 9
//Keyboard row 1 = pin 2
//Keyboard row2 = pin 3
//Keyboard row3 = pin 4
//Keyboard row4 = pin 5
//Keyboard row5 = pin 6
//Keyboard row6 = pin 7
Keyboard kb(8,9,2,3,4,5,6,7);

void setup() {
  Serial.begin(9600);
}

void loop(){
  int c = kb.getChar();
  Serial.write(c);
}
````
