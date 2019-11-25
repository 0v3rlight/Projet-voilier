// A COMPLETER

/*
Service permettant de chornométrer jusqu'à 59mn 59s 99 1/100
Utilise un timer au choix (TIMER1 à TIMER4).
Utilise la lib MyTimers.h /.c
*/


#include <stdio.h>
#include <stdlib.h>
#include "Chrono.h"
#include "MyTimer.h"
#include "moteur.h"
#include "stm32f1xx_ll_gpio.h"

void config_gpio_moteur(){
	
	//enable clock gpio
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	
	//PA1 en output pushpull
	LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_1,LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinOutputType(GPIOA, LL_GPIO_PIN_1, LL_GPIO_OUTPUT_PUSHPULL);
	
	//PA2 en output pushpull
	LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_2,LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinOutputType(GPIOA, LL_GPIO_PIN_2, LL_GPIO_OUTPUT_PUSHPULL);
	
}


/*void init_timer_pwm_input(TIM_TypeDef * Timer){
	
	if (Timer == TIM1)	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	if (Timer == TIM2)	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	if (Timer == TIM3)	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	if (Timer == TIM4)	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	
}*/



