// This is the code for our Principles of Engineering project

// pitches is a file defining different pitches
#include "pitches.h"

// wire is the library that allows communication with the accelerometer using I2C
#include <Wire.h>

// needed for communicating with this particular accelerometer
#include "SparkFun_MMA8452Q.h"

// create instance of the MMA8452 class for accelerometer
MMA8452Q accel;
int note;

void setup() { // this code runs once
  // initialize serial
  Serial.begin(9600);
  Serial.println("Setup");

  // initialize pins for buttons
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);



  // initialize wire library
  Wire.begin();

  // check if accelerometer is connected
  if (accel.begin() == false) {
    Serial.println("Not Connected. Please check connections and read the hookup guide.");
    while (1);
  }

}


void loop() {

  // button code
  if (digitalRead(2) == 1) {
    Serial.print(" Button 1");
    note = NOTE_B4;
    tone(8, note, 1000 / 16);
  }
  if (digitalRead(3) == 1) {
    Serial.print(" Button 2");
    note = NOTE_A4;
    tone(8, note, 1000 / 16);
  }
  if (digitalRead(4) == 1) {
    Serial.print(" Button 3");
    note = NOTE_G4;
    tone(8, note, 1000 / 16);
  }

  // code for force sensitive resistor
  long force = analogRead(A0);
  if (force > 5) {
    Serial.print(" Force: ");
    Serial.print(force);

    // currently the force sensor plays a tone dependent on how hard it is pushed
    // eventually, this reading may control volume or some other aspect of sound
    tone(8, force + 100, 1000 / 16);
  }

  // flex sensor code
  // Read the ADC, and calculate voltage and resistance from it
  int flexADC = analogRead(A1);
  if (flexADC < 500) {
    note = NOTE_E2;
    tone(8, note, 0);
    Serial.print("Flex");
    Serial.print(flexADC);
  }
  //  else{
  //    Serial.println(flexADC);
  //    noTone(8);
  //    Serial.println(noise);
  //  }

  // accelerometer code
  if (accel.available()) {  // Wait for new data from accelerometer
    // Acceleration of x, y, and z directions in g units (between 0 and 1)
    float ax = (accel.getCalculatedX());
    float ay = (accel.getCalculatedY());
    float az = (accel.getCalculatedZ());

    // prints accelerometer values if accelerometer is not flat (in z direction)
    if (abs(az) < 0.85) {
      Serial.print("");
      Serial.print("a(x): ");
      Serial.print(ax);
      Serial.print("\t");
      Serial.print("a(y): ");
      Serial.print(ay);
      Serial.print("\t");
      Serial.print("a(z): ");
      Serial.println(az);

      // currently makes a tone whose pitch is dependent on the absolute value of
      // acceleration in the x direction, multipled by 700
      // eventually all readings of the accelerometer will be involved and they
      // will control different aspects of the sound
      noTone(8);
      int noteDurations[] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
    for (int thisNote = 0; thisNote < 20; thisNote++) {
      int noteDuration = 1000 / noteDurations[thisNote];
      //Serial.print(abs(ay));
     //int thisPitch = map(az, -1, 1, 31, 200);
      //Serial.print(thisPitch);
      // play the pitch:
      //tone(8, note+thisPitch, noteDuration*6000);
      //note = note+thisPitch;
      tone(8,note+abs(ax)*300, noteDuration*6000);
      delayMicroseconds(10000);
    }
    Serial.println("");
    }
  }
}
