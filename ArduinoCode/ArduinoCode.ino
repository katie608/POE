
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
}


void loop() {
  int button1Mode = digitalRead(2);
//  Serial.print();
  if (digitalRead(2)==1) {
    Serial.println("Button 1 press");
    // tone goes here
  }
    if (digitalRead(3)==1) {
    Serial.println("Button 2 press");
    // tone
  }
    if (digitalRead(4)==1) {
    Serial.println("Button 3 press");
    // tone
  }
  
  
}
