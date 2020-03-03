/*
 * main.c
 *
 *  Created on: Feb 25, 2020
 *      Author: MELMA
 */


#include "HAL/LCD/Inc/LCD.h"
#include "MCAL/ADC/Inc/ADc.h"
#include "MCAL/ADC/Inc/ADc.h"
#include "MCAL/DIO/Inc/Dio.h"
#include "MCAL/I2c/inc/i2c.h"





void main (void)
{
uint8_t result ;

	// LCD PORT
	Dio_vidSetPortDirection(Dio_PORTB,Dio_Output);
	//LCD CONTROL
	Dio_vidSetPinDirection(Dio_PORTC,0,Dio_Output);
	Dio_vidSetPinDirection(Dio_PORTC,1,Dio_Output);
	//MOTOR
	Dio_vidSetPinDirection(Dio_PORTD,6,Dio_Output);
	//led 3
	Dio_vidSetPinDirection(Dio_PORTC,2,Dio_Output);
	Dio_vidSetPinDirection(Dio_PORTC,3,Dio_Output);
	Dio_vidSetPinDirection(Dio_PORTC,4,Dio_Output);

	LCD_vidInit();
	ADC_vidInit();
	UART_Init();

}

