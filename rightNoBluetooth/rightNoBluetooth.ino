
// Sends data over serial port from left hand
void setup() {
  Serial.begin(9600);
  Serial.println("Setup Done");
}

void loop() {
  // button
  Serial.print(digitalRead(2));
  Serial.print(" ");
  Serial.print(digitalRead(3));
  Serial.print(" ");
  Serial.print(digitalRead(4));
  Serial.print(" ");
  Serial.print(digitalRead(5));
  Serial.print(" ");

  // flex sensor code
  Serial.print(analogRead(A0));
  Serial.print(" ");
  Serial.print(analogRead(A1));
  Serial.println(" ");
}
