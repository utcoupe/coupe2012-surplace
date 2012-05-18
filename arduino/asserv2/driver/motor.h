#ifndef _MOTOR_H
#define _MOTOR_H

#include "AFMotor.h"

extern AF_DCMotor moteurG;
extern AF_DCMotor moteurD;


void initPWM();

void setLeftPWM(int value);

void setRightPWM(int value);

#endif
