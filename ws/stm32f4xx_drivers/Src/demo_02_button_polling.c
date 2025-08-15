/*
 * 002led_button.c
 *
 *  Created on: Aug 10, 2025
 *      Author: micom
 */


#include "stm32f407xx.h"
#define HIGH 1
#define BTN_PRESSED HIGH

void delay(void){
	for(uint32_t i = 0; i < 500000/2; i++);
}
int main(void)
{
	// LED output
	GPIO_PeriClockControl(GPIOD, ENABLE);

	GPIO_Handle_t GPIO_LED, GPIObtn;
	GPIO_LED.pGPIOx = GPIOD;
	GPIO_LED.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GPIO_LED.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIO_LED.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_LED.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_LED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12; GPIO_Init(&GPIO_LED);
	GPIO_LED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13; GPIO_Init(&GPIO_LED);
	GPIO_LED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14; GPIO_Init(&GPIO_LED);
	GPIO_LED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15; GPIO_Init(&GPIO_LED);

	// btn press input
	GPIObtn.pGPIOx = GPIOA;
	GPIObtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_PIN_NO_0;
	GPIObtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GPIObtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIObtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOA, ENABLE);

	GPIO_Init(&GPIObtn);

	while(1){
		if(GPIO_ReadFromInputPin(GPIOA,GPIO_PIN_NO_0) == BTN_PRESSED){
			delay();
			GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_12);
			GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_13);
			GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_14);
			GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_15);
		}
	}
	return 0;
}

