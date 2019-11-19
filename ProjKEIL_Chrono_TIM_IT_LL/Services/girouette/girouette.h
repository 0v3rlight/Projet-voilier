#ifndef GIROUETTE_H
#define GIROUETTE_H



#include "stm32f103xb.h"
#include "stm32f1xx_ll_gpio.h"
#include "stm32f1xx_ll_tim.h"
#include "MyTimer.h"


void init_girouette() ;
int angle_girouette() ;

#endif