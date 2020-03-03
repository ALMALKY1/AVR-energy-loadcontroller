#include "../Inc/LCD.h"

#include "util/delay.h"

#include "../../../MCAL/DIO/Inc/Dio.h"

/************************************************
 * Description: Shall Initialize LCD Module

 * Input      : None
 * Output     : None
 * *********************************************/
void LCD_vidInit(void)
{
	/*Wait for 30ms*/
	_delay_ms(30);

	/*Send Funcltion_Set Command*/
	LCD_vidWriteCommand(LCD_FUNCTION_SET);

	/*Wait for 1ms*/
	_delay_ms(1);

	/*Send Display Status Command*/
	LCD_vidWriteCommand(LCD_DISPLAY_ON);

	/*Wait for 1ms*/
	_delay_ms(1);

	/*Send Display_Clear Command*/
	LCD_vidWriteCommand(LCD_CLEAR);

	/*Wait for 2ms*/
	_delay_ms(2);

	/*Send the configured Entry Mode*/
	LCD_vidWriteCommand(LCD_ENTRY_MODE);
}

/************************************************
 * Description: Shall Initialize LCD Module
 * Input      : None
 * Output     : None
 * Last_Author: MALKY
 * **********************************************/
void LCD_vidWriteCommand(uint8_t Command)
{
	/*Clear RS Signal*/
	Dio_vidWritePin(Dio_PORTC, 0, Dio_Low);

	/*Write the Command to the Data Port*/
	Dio_vidWritePort(Dio_PORTB, Command);

	/*Set the Enable Signal*/
	Dio_vidWritePin(Dio_PORTC, 1, Dio_High);

	/*Wait for a while (1ms)*/
	_delay_ms(1);

	/*Clear Enable Signal*/
	Dio_vidWritePin(Dio_PORTC, 1, Dio_Low);

	/*Wait for the LCD to finish executing*/
	_delay_ms(10);
}

/************************************************
 * Description: Shall Initialize LCD Module
 * Input      : None
 * Output     : None
 * *********************************************/
void LCD_vidWriteData(uint8_t Data)
{
	/*Set RS Signal*/
	Dio_vidWritePin(Dio_PORTC, 0, Dio_High);


	/*Write the Data to the Data Port*/
	Dio_vidWritePort(Dio_PORTB, Data);

	/*Set the Enable Signal*/
	Dio_vidWritePin(Dio_PORTC, 1, Dio_High);

	/*Wait for a while (1ms)*/
	_delay_ms(1);

	/*Clear Enable Signal*/
	Dio_vidWritePin(Dio_PORTC, 1, Dio_Low);

	/*Wait for the LCD to finish executing*/
	_delay_ms(10);
}

/************************************************
 * Description: Shall Initialize LCD Module
 * Input      : None
 * Output     : None
 * *********************************************/
void LCD_vidGoTo(uint8_t Line, uint8_t Column)
{
	uint8_t LineBase ;

	if (Column >= 1 && Column <= 16)
	{
		switch(Line)
		{
		case 1:
			LineBase = 0x00;
			break;
		case 2:
			LineBase = 0x40;
			break;
		}

		LCD_vidWriteCommand(LCD_MOVE_CURSOR + (LineBase + (Column - 1)));
	}
}
/************************************************
 * Description: Shall Initialize LCD Module
 * Input      : None
 * Output     : None
 * *********************************************/
void LCD_vidWriteString(uint16_t * Message)
{
	while((*Message) != '\0')
	{
		LCD_vidWriteData(*Message);

		Message++;
	}
}

/************************************************
 * Description: Prints a Number on the LCD
 * Input      : None
 * Output     : None
 * Last_Author: MALKY
 * *********************************************/
void LCD_vidPrintNumber(uint32_t Number)
{
	uint32_t Factor = 1;
	uint32_t Temp;

	Temp = Number / 10;
	while (Temp != 0)
	{
		Temp = Temp / 10;
		Factor = Factor * 10;
	}

	Temp = Number;
	while(Temp != 0)
	{
		LCD_vidWriteData((Temp / Factor) + 0x30);
		Temp = Temp % Factor;
		Factor = Factor / 10;
	}
}
