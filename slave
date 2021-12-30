/*Slave CODE*/
#include <Servo.h>

Servo myServo;
int const servoPin = 6; //change to whatever pin we connect the servo to
boolean receivedSignal;
int angle;

void setup() {
  Serial.begin(9600); // Communication rate of the Bluetooth module
  
  myServo.attach(servoPin);
  receivedSignal = false;
  angle = 0;
}

void loop() {
 if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    int rec = Serial.read(); // Reads the data from the serial port
    if(rec == 1) receivedSignal = true; //If the signal received is the one sent from the master set the received signa; value to true
 }
  // put your main code here, to run repeatedly:
  if(receivedSignal){
    if(angle == 0){
      angle = 180;
      myServo.write(angle);
      receivedSignal = false;
      delay(510);
    } else if (angle == 180){
      angle = 0;
      myServo.write(angle);
      receivedSignal = false;
      delay(510);
    }
  }
}
