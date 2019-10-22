
int timeAtInterrupt = millis();
int counter = 0;
bool buttonflag2 = false;
bool buttonflag3 = false;
bool buttonflag4 = false;

void setup() {
  // initialize serial
  Serial.begin(9600);
  Serial.println("Setup");

  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), I2, RISING);
  attachInterrupt(digitalPinToInterrupt(3), I3, RISING);
  attachInterrupt(digitalPinToInterrupt(4), I4, RISING);
}

void I2() {
  onButtonPress(2);
}

void I3(){
  onButtonPress(3);
}

void I4(){
  onButtonPress(4);
}

void onButtonPress(int b) {
  // check if going high to low
  // ignore future changes for next 0.5 seconds
    if ((millis() - timeAtInterrupt) > 50){
      timeAtInterrupt = millis();
      if (b == 2) {
        buttonflag2 = true;
      }
      if (b == 3) {
        buttonflag3 = true;
      }
      if (b == 4) {
        buttonflag4 = true;
      }

      counter++;
    } 
}


void loop() {
  int button1Mode = digitalRead(2);
//  Serial.print();
  if (buttonflag2) {
    Serial.println("Button 1 press");
    buttonflag2 = false;
  }
    if (buttonflag3) {
    Serial.println("Button 2 press");
    buttonflag3 = false;
  }
    if (buttonflag4) {
    Serial.println("Button 3 press");
    buttonflag4 = false;
  }
  
  
}
