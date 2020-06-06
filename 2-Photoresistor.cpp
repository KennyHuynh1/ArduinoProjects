#include <Arduino.h>

/**
 * When the ambient light is low, the LED turns on.
 * 
 */

int LEDPin = 13;
int sensorPin = A5;
int sensorValue = 0;
float Rref = 220; // 220 ohm
float Vin = 5; // 5 volts
float Vphoto = 0;
float Rphoto = 0;

void setup()
{
  // initialize LED digital pin as an output.
  pinMode(LEDPin, OUTPUT);

  // initialize serial communication at 9600 bps
  Serial.begin(9600);
}

void loop()
{
  sensorValue = analogRead(sensorPin); // read from sensorPin the voltage from 0-1023

  Vphoto = Vin * sensorValue / 1023; // convert Vphoto to volts

  Rphoto = Rref * Vphoto / (Vin - Vphoto); // voltage division

  int ambientLight = 30000;

  if(Rphoto > ambientLight) // ambient light is around 30kohm, if Rphoto > 40000 => almost no light then light on LED
  {
    digitalWrite(LEDPin, HIGH);
  }else
  {
    digitalWrite(LEDPin, LOW);
  }
  

  // print the Rphoto with a delay of 1000 ms
  // Serial.println(Rphoto);
  // delay(1000);

}