// prints data over Bluetooth from right hand

#include <SoftwareSerial.h>

// set up bluetooth code
int rx = 6;
int tx = 7;
SoftwareSerial mySerial(rx, tx); // RX, TX

// wire is the library that allows communication with the accelerometer using I2C
#include <Wire.h> 

// needed for communicating with this particular accelerometer
#include "SparkFun_MMA8452Q.h" 

// create instance of the MMA8452 class for accelerometer
MMA8452Q accel;  

void setup() {
  Serial.begin(9600);
  Serial.println("test"   );
  mySerial.begin(9600);

  // check if accelerometer is connected
  while (accel.init() == 0) {
    Serial.println("Not Connected. Please check connections and read the hookup guide.");
    delay(200);
  }

  Serial.println("Done");
  
}

void loop() {
  // accelerometer code
    // Acceleration of x, y, and z directions in g units (between 0 and 1)
    float ax = (accel.getCalculatedX());
    float ay = (accel.getCalculatedY());
    float az = (accel.getCalculatedZ());
    mySerial.print(ax);
    mySerial.print(" ");
    mySerial.print(ay);
    mySerial.print(" ");
    mySerial.println(az);

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
  // button 4
  mySerial.print(digitalRead(5));
  mySerial.print(" ");

  // flex sensor code
  mySerial.print(analogRead(A0));
  mySerial.print(" ");
  mySerial.print(analogRead(A1));
  mySerial.print(" ");

}
