/*
 * main.c
 *
 *  Created on: May 30, 2021
 *      Author: fatma
 */

#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"RCC_interface.h"
#include"DIO_interface.h"

void main()
{
	/* initiat system clock */
	RCC_voidInitSysClock();

	/* enable periperal port A on  APb2 */
	RCC_voidEnablePrephiralClock(RCC_APB2, RCC_PORTA);

	/* configure pin 0 as output push pull 10MHZ */
	GPIO_voidSetPinDirection(GPIOA , PIN0, OUTPUT_SPEED_10MHZ_PP);

	/* configure pin 1 as output push pull 10MHZ */
	GPIO_voidSetPinDirection(GPIOA , PIN1, OUTPUT_SPEED_10MHZ_PP);

	u16 w = 1000 ;

	while(1)
	{
		/* SET pin 0 HIGH & pin 1 LOW*/
		GPIO_voidSetPinValue(GPIOA, PIN0, HIGH);
		GPIO_voidSetPinValue(GPIOA, PIN1, LOW);

		/* wait for 1s*/
		for(int i = 0 ; i < w ; i++ )
		{
			for( int j =0 ; j< w ;j++)
			{
				asm("NOP");
			}
		}
		/* SET pin 1 HIGH & pin 0 LOW*/
		GPIO_voidSetPinValue(GPIOA, PIN1, HIGH);
		GPIO_voidSetPinValue(GPIOA, PIN0, LOW);

		for(int i = 0 ; i < w ; i++ )
		{
			for( int j =0 ; j< w ;j++)
			{
				asm("NOP");
			}
		}

	}
}
