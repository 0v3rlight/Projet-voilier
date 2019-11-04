/* Commande des voiles */
/* Acteur : Servo_Moteur */

#include "girouette.h"

void init_girouette() {
	
	// Initialisation du timer TIM3 en capture compare
	int Arr = 0;
	int Psc = 0 ;
	MyTimer_Conf_comparecapture(TIM3,Arr,Psc) ;
	
	// Initialisation des GPIOA 5 (Index) et GPIOA 6 (CHA) et GPIOA 7 (CHB)
	LL_GPIO_SetPinMode(GPIOA,5,LL_GPIO_MODE_FLOATING);
	LL_GPIO_SetPinMode(GPIOA,6,LL_GPIO_MODE_FLOATING);
	LL_GPIO_SetPinMode(GPIOA,7,LL_GPIO_MODE_FLOATING);
	
}

int angle_girouette() {
	
}