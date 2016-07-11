/*******************************************
/ Program to see the signals sent by boat's 
/ radio to the serial monitor.
/ Adapted form code by Minds-i Inc.
/ http://mindsieducation.com/
/ Carol Hazlett 7/01/2016
/********************************************/

#include <MINDSi.h>   //Minds-i library
#include <Servo.h>    //Modified servo library
 
Servo leftMotor, rightMotor, steer;   //assign names to ESC and steering servo

int val1;  //steering variable
int val2;  //Left ESC variable
int val3;  //right ESC variable

void setup() {
  Serial.begin(9600);   //start serial session
  leftMotor.attach(5);  //assign pin to Left ESC
  rightMotor.attach(6); //assign pin to right ESC
  steer.attach(4);      //assign pin to steering servo
  leftMotor.write(90);  //send neutral signal to left ESC
  rightMotor.write(90); //send neitral signal to right ESC
  steer.write(90);      //send centering signal to steering servo.
  delay(2000);          //delay to arm ESC
}

void loop() {
  val1 = getRadio(3);   //retrieves signal from radio chan 2
  val2 = getRadio(8);   //retrieves signal from radio chan 3
  val3 = getRadio(2);   //retrieves signal from radio chan 1 
    Serial.print("Steer =  ");//print name of signal
    Serial.println(val1);    //print variable value from radio
    Serial.print("Left =   "); //print name of signal
    Serial.println(val2);    //print variable value from radio
    Serial.print("Right =  ");//print name of signal
    Serial.println(val3);    //print variable value from radio
    delay(300);              //delay to make display more readable
  }

  
