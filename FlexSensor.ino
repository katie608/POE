const int FLEX_PIN = A0; // Pin connected to voltage divider output
const int threshold = 500;
int noise = 0;
#include "pitches.h"

void setup() 
{
  Serial.begin(9600);
  pinMode(FLEX_PIN, INPUT);
}

void loop() 
{
  // Read the ADC, and calculate voltage and resistance from it
  int flexADC = analogRead(FLEX_PIN);
  if (flexADC < 500){
    Serial.println(flexADC);
    tone(8,NOTE_G3 ,0);
  }
  else{
    Serial.println(flexADC);
    noTone(8);
    Serial.println(noise);
  }
  delay(500);
}
