#include <Servo.h>    //modified servo library
#include <MINDSi.h>    //Minds-i library

/**********************************************
/ Program to drive an Arduino equipped RC boat
/ using the RC radio transmitter.
/ Adapted from code by Minds-i Inc.
/ http://mindsirobotics.com/
/ Carol Hazlett 7/01/2016
/**********************************************/
    
Servo leftMotor, rightMotor, steer;
int driveSigL, driveSigR, steerSig; //assign variables

void setup() {
  Serial.begin(9600);
  leftMotor.attach(5);  //assign pin 5 to left ESC
  rightMotor.attach(6); //assign pin 6 to right ESC
  steer.attach(4);      //assign pin 4 to steering servo
  leftMotor.write(90);  //send neutral value to left ESC
  rightMotor.write(90); //send neutral value to right ESC
  steer.write(90);      //and steering servo
  delay(5000);          //delay to arm ESC
}

void loop() {
  driveSigL = getRadio(8);     //input radio signal to variable
  driveSigR = getRadio(2);     //input radio signal to variable
  steerSig = getRadio(3);      //input radio signal to variable
  leftMotor.write(driveSigL);  //send radio signal to left ESC
  rightMotor.write(driveSigR); //send radio signal to right ESC
  steer.write(steerSig);       //send radio signal to steering servo
  //testing();
}

void testing(){
  Serial.print("Steer:  ");       //print name of signal
    Serial.println(steerSig);     //print variable value from radio
    Serial.print("Left:  ");      //print name of signal
    Serial.println(driveSigL);    //print variable value from radio
    Serial.print("Right:  ");     //print name of signal
    Serial.println(driveSigR);    //print variable value from radio
    delay(300);                   //delay to make display more readable
}

