

/***************************************************
* Module name: main.c
*
* Copyright 2020 Company CDAC(T)
* All Rights Reserved.
*
*  The information contained herein is confidential
* property of Company. The user, copying, transfer or
* disclosure of such information is prohibited except
* by express written agreement with Company.
*
*
* Module Description:
* SPI test pgm
*
***************************************************/

/*  Include section
*
*
***************************************************/

/**
 @file led_toggle_pgm.c
 @brief Main program to toggle the LED's
*/


#include "stdlib.h"
#include "config.h"
#include "gpio.h"


/** 
 * @brief Toggle leds LD5,LD6 & LD7.
 * @details Toggle LEDs at finite intervals.
 * @param[in] No input parameter 
 * @param[Out] No output parameter 
*/
void main()
{
	US sw_status = 0;
	UI i = 0;
	printf("\n\r Please check the LD5,LD6 and LD7 status on Dev. Board");

	GPIO_set_pin_mode(PIN_25, OUT);
	
	while(1)
	{
		//Turn ON LEDs 5, 6, 7 at GPIO pins 16,17,18 respectively.
		
		
		GPIO_write_pin(PIN_25, HIGH);
		printf("\n\r LEDs ON");
		for(i=0; i< 0x800000;i++); // Delay

		//Turn OFF LEDs 5, 6, 7 at GPIO pins 16,17,18 respectively.

		GPIO_write_pin(PIN_25, LOW);
		printf("\n\r LEDs OFF");

		for(i=0; i< 0x800000;i++); // Delay

		
	}
	
}




