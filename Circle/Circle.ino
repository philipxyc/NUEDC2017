#include "MeMegaPi.h"

#include "MeGyro.h"

#include <Wire.h>
MeGyro gyro;
MeMegaPiDCMotor motor1(PORT1A);
MeMegaPiDCMotor motor2(PORT2A);
MeMegaPiDCMotor motor3(PORT3A);
MeMegaPiDCMotor motor4(PORT4A);

uint8_t fullSpeed = 255;
uint8_t root2Speed = fullSpeed/1.414;

uint8_t Speed1 = 150;
uint8_t Speed2 = 255;
unsigned int I = 500;
float originx,originy,originz;


void setup()

{

  Serial.begin(9600);

  gyro.begin();

  motor2.run(255);

  motor4.run(255);

  gyro.update();
  originx = gyro.getAngleX();
  originy = gyro.getAngleY();
  originz = gyro.getAngleZ();
}



void loop()

{
  motor1.run(fullSpeed);
  delay(50);
  motor1.run(root2Speed);
  motor2.run(root2Speed);
  delay(100);
  motor1.stop();
  
  motor2.run(fullSpeed);
  delay(50);
  motor2.run(root2Speed);
  motor3.run(root2Speed);
  delay(100);
  motor2.stop();
  
  motor3.run(fullSpeed);
  delay(50);
  motor3.run(root2Speed);
  motor4.run(root2Speed);
  delay(100);
  motor3.stop();
  
  motor4.run(fullSpeed);
  delay(50);
  motor4.run(root2Speed);
  motor1.run(root2Speed);
  delay(100);
  motor4.stop();
}

void forward1(int mspeed){

  motor1.run(mspeed);

  motor3.run(-mspeed);

}

void forward2(int mspeed){

  motor2.run(mspeed);

  motor4.run(-mspeed);

}

void forward3(int mspeed){

  motor3.run(mspeed);

  motor1.run(-mspeed);

}

void forward4(int mspeed){

  motor4.run(mspeed);

  motor2.run(-mspeed);

}

void selfMaintain(int mspeed){
  
  motor2.run(mspeed);
  
  motor4.run(-mspeed);

}
