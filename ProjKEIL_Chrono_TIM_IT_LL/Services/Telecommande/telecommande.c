// A COMPLETER

/*
Service permettant de chornométrer jusqu'à 59mn 59s 99 1/100
Utilise un timer au choix (TIMER1 à TIMER4).
Utilise la lib MyTimers.h /.c
*/



#include "Chrono.h"
#include "MyTimer.h"
#include "telecommande.h"
#include "stm32f1xx_ll_gpio.h"

void config_gpio(){
	
	//enable clock gpio
	
	
	//PB6 en floating input
	LL_GPIO_SetPinMode(GPIOB,LL_GPIO_PIN_6,LL_GPIO_MODE_FLOATING);
	
	//PA1 en output pushpull
	LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_1,LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinOutputType(GPIOA, LL_GPIO_PIN_1, LL_GPIO_OUTPUT_PUSHPULL);
	
	//PA2 en output pushpull
	LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_2,LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinOutputType(GPIOA, LL_GPIO_PIN_2, LL_GPIO_OUTPUT_PUSHPULL);
	
}


void init_timer_pwm_input(TIM_TypeDef * Timer){
	
	if (Timer == TIM1)	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	if (Timer == TIM2)	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	if (Timer == TIM3)	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	if (Timer == TIM4)	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	
	Timer->CCMR1 |= TIM_CCMR1_CC1S_0;
	Timer->CCMR1 &= ~TIM_CCMR1_CC1S_1;
	
	Timer->CCR1 &= TIM_CCER_CC1P;
	
	Timer->CCMR1 &= ~TIM_CCMR1_CC2S_0;
	Timer->CCMR1 |= TIM_CCMR1_CC2S_1;
	
	Timer->CCR2 |= TIM_CCER_CC2P; 
	
	Timer->SMCR |= TIM_SMCR_TS_0;
	Timer->SMCR &= ~TIM_SMCR_TS_1;
	Timer->SMCR |= TIM_SMCR_TS_2;
	
	Timer->SMCR &= ~TIM_SMCR_SMS_0;
	Timer->SMCR &= ~TIM_SMCR_SMS_1;
	Timer->SMCR |= ~TIM_SMCR_SMS_2;
	
	Timer->CCER |= TIM_CCER_CC1E;
	Timer->CCER |= TIM_CCER_CC2E;
}

int get_period(TIM_TypeDef * Timer){
	return(Timer->CCR2);	
}

int get_angle(int per){
	
	int angle = 360*per - 540;
	
	//traitement angle
	
	return(angle);
	
	
	
}

