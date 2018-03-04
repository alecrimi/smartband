/*
  A. Crimi 14.02.2018
  This script read the AnalogSerial input given by the 
  Reads an analog input on pin 0, 
  prints the result to the serial monitor,
  if value beyond certain value turn on the led
  
  */

//#include "Adafruit_FONA.h"
#define FONA_RX 2
#define FONA_TX 3
#define FONA_RST 4

int threshold = 200;  // threshold to detect contraction
int led = 7;// Pin D7 has an LED connected on FLORA.
//Adafruit_FONA fona = Adafruit_FONA(FONA_RST);
char sendto[20]; //phone number to send the message

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize flora led
  pinMode(led, OUTPUT); 
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0. Inputs are in millivolt between 0 and 5V ?
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  
  // If contraction (input) above a threshold turn on the led
  if (sensorValue > threshold)
  {
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    //fona.sendSMS(sendto, "BABY IS COMING!")
  }
  
  delay(1);        // delay in between reads for stability
}
