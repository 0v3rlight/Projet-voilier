// RIEN A MODIFIER //

#ifndef TELECOMMANDE_H
#define TELECOMMANDE_H

#include "stm32f103xb.h" 


void config_gpio_telecommande(void);

void init_timer_pwm_input(TIM_TypeDef * Timer);

int get_period(TIM_TypeDef * Timer);

int get_angle(int per);

float get_vitesse(int angle);

int get_sens(int angle);



#endif
