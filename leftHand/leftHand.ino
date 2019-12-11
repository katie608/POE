// prints data over bluetooth from left hand

#include <SoftwareSerial.h>

// set up bluetooth code
int rx = 6;
int tx = 7;
SoftwareSerial mySerial(rx, tx); // RX, TX

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);

  Serial.println("Setup Done");
  
}

void loop() {  

  // code for force sensitive resistor
  mySerial.print(analogRead(A0));
  mySerial.print(" ");
  mySerial.print(analogRead(A1));
  mySerial.print(" ");
  mySerial.print(analogRead(A5));
  mySerial.print(" ");
  mySerial.print(analogRead(A4));
  mySerial.print(" ");

  // flex sensor code
  mySerial.print(analogRead(A3));
  mySerial.print(" ");
  mySerial.print(analogRead(A2));
  mySerial.println(" ");

}
