#include <SoftwareSerial.h>

// set up bluetooth code
int rx = 2;
int tx = 3;
SoftwareSerial mySerial(2, 3); // RX, TX

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
  // put your main code here, to run repeatedly:
  Serial.println("Printing over Serial"   );
  mySerial.println("Printing over bluetooth");

//
//    // accelerometer code
//  if (accel.available()) {  // Wait for new data from accelerometer
//    // Acceleration of x, y, and z directions in g units (between 0 and 1)
//    Serial.print("a(x): ");
//    Serial.print(accel.getCalculatedX());
//    Serial.print("\t");
//    Serial.print("a(y): ");
//    Serial.print(accel.getCalculatedY());
//    Serial.print("\t");
//    Serial.print("a(z): ");
//    Serial.println(accel.getCalculatedZ());
//  }

}
