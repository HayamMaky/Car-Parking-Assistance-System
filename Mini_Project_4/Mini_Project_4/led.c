/*
 * led.c
 *
 *  Created on: Oct 8, 2024
 *      Author: Hayam
 */
#include"led.h"
#include"gpio.h"
#include"std_types.h"
#include "util/delay.h"

/*Initializes all Leds (red, green, blue) pins direction.Turn off all the Leds */
void LEDS_init(void)
{
	/*Initializes all Leds (red, green, blue) pins direction. */
	GPIO_setupPinDirection(RED_LED_PORT_ID, RED_LED_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, PIN_OUTPUT);
	/*Turn off all the Leds*/
#ifdef POSITVE_LOGIC
	GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_LOW);
	GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_LOW);
	GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_LOW);
#elif NEGATIVE_LOGIC
	GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_HIGH);
	GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_HIGH);
	GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_HIGH);
#endif
}

/*Turns on the specified LED.*/
void LED_on(LED_ID id)
{
#ifdef POSITVE_LOGIC
	switch(id)
	{
	case RED:
		GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_HIGH);
		break;
	case GREEN:
		GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_HIGH);
		break;
	case BLUE:
		GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_HIGH);
		break;
	}
#elif NEGATIVE_LOGIC
	switch(id)
			{
			case RED:
				GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_LOW);
				break;
			case GREEN:
				GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_LOW);
				break;
			case BLUE:
				GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_LOW);
				break;
			}
#endif
}

/*Turns off the specified LED.*/
void LED_off(LED_ID id)
{
#ifdef POSITVE_LOGIC
	switch(id)
		{
		case RED:
			GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_LOW);
			break;
		case GREEN:
			GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_LOW);
			break;
		case BLUE:
			GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_LOW);
			break;
		}
#elif
	switch(id)
		{
		case RED:
			GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_HIGH);
			break;
		case GREEN:
			GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_HIGH);
			break;
		case BLUE:
			GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_HIGH);
			break;
#endif
}
void LED_all_Are_ON(void)
{
	LED_on(RED);
	LED_on(GREEN);
	LED_on(BLUE);
}
void LED_all_Are_OFF(void)
{
	LED_off(RED);
	LED_off(GREEN);
	LED_off(BLUE);
}
void LED_all_LEDs_Are_flashing(void)
{
	LED_all_Are_ON();
	_delay_ms(1000);
	LED_all_Are_OFF();
	_delay_ms(1000);
}
