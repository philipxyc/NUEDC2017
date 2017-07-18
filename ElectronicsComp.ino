/**
 * \par Copyright (C), 2012-2016, MakeBlock
 * @file    MeMegaPiDCMotorTest.ino
 * @author  MakeBlock
 * @version V1.0.0
 * @date    2016/05/17
 * @brief   Description: this file is sample code for MegaPi DC motor device.
 *
 * Function List:
 *    1. void MeMegaPiDCMotorTest::run(int16_t speed)
 *    2. void MeMegaPiDCMotorTest::stop(void)
 *
 * \par History:
 * <pre>
 * <Author>     <Time>        <Version>      <Descr>
 * Mark Yan     2016/05/17    1.0.0          build the new
 * </pre>
 */
#include "MeMegaPi.h"
#include "MeGyro.h"
#include <Wire.h>

MeGyro gyro;

MeMegaPiDCMotor motor1(PORT1A);

MeMegaPiDCMotor motor2(PORT2A);

MeMegaPiDCMotor motor3(PORT3A);

MeMegaPiDCMotor motor4(PORT4A);

uint8_t motorSpeed = 255;
uint8_t changeSpeed = 0;

unsigned int i = 500;

void setup()
{
  Serial.begin(9600);
  gyro.begin();
  motor1.run(150);
}

void loop()
{
  
}
void forward1(){
  motor1.run(motorSpeed);
  motor3.run(-motorSpeed);
}
void forward2(){
  motor2.run(changeSpeed);
  motor4.run(-changeSpeed);
}
void forward3(){
  motor3.run(motorSpeed);
  motor1.run(-motorSpeed);
}
void forward4(){
  motor4.run(changeSpeed);
  motor2.run(-changeSpeed);
}
