// prints bluetooth data to 

#include <SoftwareSerial.h>

// set up bluetooth code
int rx = 6;
int tx = 7;
SoftwareSerial mySerial(rx, tx); // RX, TX

//// wire is the library that allows communication with the accelerometer using I2C
//#include <Wire.h> 
//
//// needed for communicating with this particular accelerometer
//#include "SparkFun_MMA8452Q.h" 
//
//// create instance of the MMA8452 class for accelerometer
//MMA8452Q accel;  

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);

//  // check if accelerometer is connected
//  if (accel.begin() == false) {
//    Serial.println("Not Connected. Please check connections and read the hookup guide.");
//    while (1);
//  }
}

void loop() {
//  Serial.println("Printing over Serial"   );
//  mySerial.println("Printing over bluetooth");



  // button code
  // button 1
  mySerial.print(digitalRead(2));
  mySerial.print(" ");
  // button 2
  mySerial.print(digitalRead(3));
  mySerial.print(" ");
  // button 3
  mySerial.print(digitalRead(4));
  mySerial.print(" ");
  

  // code for force sensitive resistor
  mySerial.print(analogRead(A0));
  mySerial.print(" ");


  // flex sensor code
  mySerial.println(analogRead(A1));
  mySerial.print(" ");


//  // accelerometer code
//  if (accel.available()) {  // Wait for new data from accelerometer
//    // Acceleration of x, y, and z directions in g units (between 0 and 1)
//    mySerial.print(accel.getCalculatedX());
//    mySerial.print(" ");
//    mySerial.print(accel.getCalculatedY());
//    mySerial.print(" ");
//    mySerial.println(accel.getCalculatedZ());
//  }

}
