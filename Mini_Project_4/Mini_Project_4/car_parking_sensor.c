/*
 * car_parking_sensor.c
 *
 *  Created on: Oct 16, 2024
 *      Author: Hayam
 */
#include <avr/io.h>
#include "buzzer.h"
#include "lcd.h"
#include "led.h"
#include "ultrasonic.h"
int main(void)
{
	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);
	Buzzer_init();
	LCD_init();
	LEDS_init();
	Ultrasonic_init();
	uint16 dis=0;
	LCD_displayString("Distance=");
	LCD_displayStringRowColumn(0,13,"cm");

	while(1)
	{

		dis=Ultrasonic_readDistance();
		LCD_moveCursor(0,10);

		if(dis<9)
		{
			LCD_intgerToString(dis);
			LCD_displayString(" ");
		}
		else
		{
			LCD_intgerToString(dis);
		}

		if(dis>20)
		{
			/*All LEDs OFF, Buzzer OFF.*/
			Buzzer_off();
			LED_all_Are_OFF();
			LCD_displayStringRowColumn(1,5,"    ");
		}
		else if(dis>15)
		{
			/*  Only Red LED ON, others OFF. */
			LED_on(RED);
			LED_off(GREEN);
			LED_off(BLUE);
			Buzzer_off();
			LCD_displayStringRowColumn(1,5,"    ");
		}
		else if(dis>10)
		{
			/*  Red and Green LEDs ON, Blue LED OFF. */
			LED_on(RED);
			LED_on(GREEN);
			LED_off(BLUE);
			Buzzer_off();
			LCD_displayStringRowColumn(1,5,"    ");
		}
		else if(dis>5)
		{
			/* All LEDs ON (Red, Green, Blue), No buzzer.*/
			LED_on(RED);
			LED_on(GREEN);
			LED_on(BLUE);
			Buzzer_off();
			LCD_displayStringRowColumn(1,5,"    ");
		}
		else if (dis<5)
		{
			/* All LEDs are flashing (Red, Green, Blue), Buzzer sounds, LCD shows "Stop."*/
			LED_all_LEDs_Are_flashing();
			Buzzer_on();
			LCD_displayStringRowColumn(1,5,"STOP");
		}
	}
}

