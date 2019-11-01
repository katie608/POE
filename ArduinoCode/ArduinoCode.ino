
#include "pitches.h"
#include <Wire.h>


int timeAtInterrupt = millis();
int counter = 0;
bool buttonflag2 = false;
bool buttonflag3 = false;
bool buttonflag4 = false;

int analogPin = A0;


#include <Wire.h>                 // Must include Wire library for I2C
#include "SparkFun_MMA8452Q.h"    // Click here to get the library: http://librarymanager/All#SparkFun_MMA8452Q
MMA8452Q accel;                   // create instance of the MMA8452 class


void setup() {
  // initialize serial
  Serial.begin(9600);
  Serial.println("Setup");

  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);

  Serial.begin(9600);
  Wire.begin();

  if (accel.begin() == false) {
    Serial.println("Not Connected. Please check connections and read the hookup guide.");
    while (1);
  }

}


void loop() {
  int button1Mode = digitalRead(2);
  if (digitalRead(2)==1) {
    Serial.print(" Button 1");
    tone(8, NOTE_B4, 1000/16);
  }
    if (digitalRead(3)==1) {
    Serial.print(" Button 2");
    tone(8, NOTE_A4, 1000/16);
  }
    if (digitalRead(4)==1) {
    Serial.print(" Button 3");
    tone(8, NOTE_G4, 1000/16);
  }

  // code for force sensitive resistor
  if (analogRead(A0)>0) {
    Serial.print(" Force: ");
    Serial.print(analogRead(A0));
    if (analogRead(A0)>250) {
      tone(8, NOTE_C4, 1000/16);
    } else if (analogRead(A0)>400) {
      tone(8, NOTE_D4, 1000/16);
    }else {
      tone(8, NOTE_E4, 1000/16);
    }
  }

  // accelerometer printing code
  if (accel.available()) {      // Wait for new data from accelerometer
    // Acceleration of x, y, and z directions in g units
    Serial.println("");
    Serial.print("a(x): ");
    Serial.print(accel.getCalculatedX(), 3);
    Serial.print("\t");
    Serial.print("a(y): ");
    Serial.print(accel.getCalculatedY(), 3);
    Serial.print("\t");
    Serial.print("a(z): ");
    Serial.print(accel.getCalculatedZ(), 3);
  }

    
}
  
  
