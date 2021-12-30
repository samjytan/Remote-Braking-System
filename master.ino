/*MASTER CODE*/

int stateB, stateL;
const int buttonPin = 6;
long timeStart;

void setup() {
  Serial.begin(9600); // Communication rate of the Bluetooth module

  pinMode(buttonPin, INPUT_PULLUP);
  stateB = digitalRead(buttonPin);
  stateL = stateB;
  timeStart = millis();
}

void loop() {
 stateB = digitalRead(buttonPin);

 if(stateB != stateL){
    if ((millis() - timeStart) > 2000) timeStart = millis();
    stateB = digitalRead(buttonPin);
    if( stateB != stateL && (millis() - timeStart) < 500){
        Serial.write(1); //Send one to motor  
    }
    
    Serial.println("Message sent");
    //delay(250);
 }
}
