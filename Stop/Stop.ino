#include "MeMegaPi.h"

#include "MeGyro.h"

#include <Wire.h>
MeGyro gyro;
MeMegaPiDCMotor motor1(PORT1A);
MeMegaPiDCMotor motor2(PORT2A);
MeMegaPiDCMotor motor3(PORT3A);
MeMegaPiDCMotor motor4(PORT4A);

uint8_t fullSpeed = 255;

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
  
  Serial.print("OX:");
  Serial.print(originx);
  Serial.print("OY:");
  Serial.print(originy);
  Serial.print("OZ:");
  Serial.println(originz);
  
  gyro.update();

  Serial.print("X:");

  Serial.print(gyro.getAngleX()-originx);

  Serial.print(" Y:");

  Serial.print(gyro.getAngleY()-originy);

  Serial.print(" Z:");

  Serial.println(gyro.getAngleZ()-originz);
  
  gyro.update();
  forward4((gyro.getAngleY()-originy)*1000);
  forward1((gyro.getAngleX()-originx)*1000);
  originx = gyro.getAngleX();
  originy = gyro.getAngleY();
  originz = gyro.getAngleZ();
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
