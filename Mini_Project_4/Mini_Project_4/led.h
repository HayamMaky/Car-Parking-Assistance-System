/*
 * led.h
 *
 *  Created on: Oct 8, 2024
 *      Author: Hayam
 */

#ifndef LED_H_
#define LED_H_

# include "std_types.h"

#define RED_LED_PORT_ID     PORTC_ID
#define RED_LED_PIN_ID      PIN0_ID
#define GREEN_LED_PORT_ID   PORTC_ID
#define GREEN_LED_PIN_ID    PIN1_ID
#define BLUE_LED_PORT_ID    PORTC_ID
#define BLUE_LED_PIN_ID     PIN2_ID

#define POSITVE_LOGIC

typedef enum
{
	RED,GREEN,BLUE
}LED_ID;


void LEDS_init(void);
void LED_on(LED_ID id);
void LED_off(LED_ID id);
void LED_all_Are_ON(void);
void LED_all_Are_OFF(void);
void LED_all_LEDs_Are_flashing(void);

#endif /* LED_H_ */
