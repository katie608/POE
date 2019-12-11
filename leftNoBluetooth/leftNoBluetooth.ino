// Sends data over serial port from left hand
void setup() {
  Serial.begin(9600);
  Serial.println("Setup Done");
}

void loop() {

  // code for force sensitive resistor
  Serial.print(analogRead(A0));
  Serial.print(" ");
  Serial.print(analogRead(A1));
  Serial.print(" ");
  Serial.print(analogRead(A4));
  Serial.print(" ");
  Serial.print(analogRead(A5));
  Serial.println(" ");
  
  // flex sensor code
  Serial.print(analogRead(A2));
  Serial.print(" ");
  Serial.print(analogRead(A3));
  Serial.print(" ");

}
