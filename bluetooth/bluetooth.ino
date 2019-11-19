// prints bluetooth data to 

#include <SoftwareSerial.h>

// set up bluetooth code
int rx = 6;//2
int tx = 7;//3
SoftwareSerial mySerial(rx, tx); // RX, TX

// wire is the library that allows communication with the accelerometer using I2C
#include <Wire.h> 

// needed for communicating with this particular accelerometer
#include "SparkFun_MMA8452Q.h" 

// create instance of the MMA8452 class for accelerometer
MMA8452Q accel;  

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);

  // check if accelerometer is connected
  if (accel.begin() == false) {
    Serial.println("Not Connected. Please check connections and read the hookup guide.");
    while (1);
  }
}

void loop() {
//  Serial.println("Printing over Serial"   );
//  mySerial.println("Printing over bluetooth");



  // button code
  // button 1
  Serial.print(digitalRead(2));
  Serial.print(" ");
  // button 2
  Serial.print(digitalRead(3));
  Serial.print(" ");
  // button 3
  Serial.print(digitalRead(4));
  Serial.print(" ");
  

  // code for force sensitive resistor
  Serial.print(analogRead(A0));
  Serial.print(" ");


  // flex sensor code
  mySerial.println(analogRead(A1));
  Serial.print(" ");


  // accelerometer code
  if (accel.available()) {  // Wait for new data from accelerometer
    // Acceleration of x, y, and z directions in g units (between 0 and 1)
    Serial.print(accel.getCalculatedX());
    Serial.print(" ");
    Serial.print(accel.getCalculatedY());
    Serial.print(" ");
    Serial.println(accel.getCalculatedZ());
  }

}
