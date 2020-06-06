#include <Arduino.h>

/**
 * Whenever the pushbutton is pressed, the LED turns on.
 * 
 */

int inputPin = 7;
int LEDPin = 13;

void setup() {
  // initialize PB digital pin as an input
  pinMode(inputPin, INPUT);
  // initialize LED digital pin as an output
  pinMode(LEDPin, OUTPUT);
}

void loop() {
  if(digitalRead(inputPin) == HIGH){ // if the pushbutton is pressed, the circuit is "switched on" and the inputPin will read a HIGH
    digitalWrite(LEDPin, HIGH);
  }else{
    digitalWrite(LEDPin, LOW);
  }
}