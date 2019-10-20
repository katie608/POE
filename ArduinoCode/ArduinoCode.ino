
int timeAtInterrupt = millis();
bool flag = false;

void setup() {
  // initialize serial
  Serial.begin(9600);
  Serial.println("Setup");

  pinMode(2, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), onButtonPress, CHANGE);
}


void onButtonPress() {
  // check if going high to low
  // ignore future changes for next 0.3 seconds
  if (digitalRead(2) == LOW){
    if ((millis() - timeAtInterrupt) > 30){
      timeAtInterrupt = millis();
        Serial.print("Button State: ");
        Serial.println(digitalRead(2));
      
    } 
  }
  
}


void loop() {
  int button1Mode = digitalRead(2);

  
  
}
