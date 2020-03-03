#include "avr/io.h"

#include "../../../common/Bit_op.h"
#include "../Inc/ADc.h"

/**************************************************************
 * Description: Shall initialize ADC module
 * Input      : None
 * Output     : None
 * Last_Author: ALMALKY
 **************************************************************/
void ADC_vidInit(void)
{
	/*Configure Prescalar (Division Factor = 1024)*/
	ADCSRA = (ADCSRA & 0xF8) | 0x07;

	/*Configure Vref (Internal Vref = VCC)*/
	ADMUX = (ADMUX &0x3F) | 0x40;

	/*Configure Right ADjusted Result, No Interrupt, No Auto-Trigger*/
	Clear_Bit(ADMUX, 5);
	Clear_Bit(ADCSRA, 3);
	Clear_Bit(ADCSRA, 5);

	/*Enable ADC module*/
	Set_Bit(ADCSRA, 7);
}

/**************************************************************
 * Description: Shall Start conversion and return conversion result
 * Input      : Channel Number
 * Output     : Conversion Result
 * Last_Author: ALMALKY
 **************************************************************/
uint16_t ADC_u16ReadChannel(uint8_t Channel)
{
	uint16_t Result = 0;

	/*Check if the ADC is currently running a conversion*/
	if (Get_Bit(ADCSRA, 6) == 0)
	{
		if (Channel >=1 && Channel <= 8)
		{
			/*Select the required channel*/
			ADMUX = (ADMUX & 0xE0) | (Channel - 1);

			/*Start Conversion on the select channel*/
			Set_Bit(ADCSRA, 6);

			/*Wait for the conversion to finish*/
			while(Get_Bit(ADCSRA, 6) != 0)
			{

			}

			/*Read the lower segment of the result first*/
			Result = ADCL;

			/*Read the higher segment of the result*/
			Result |= (ADCH << 8);
		}
	}
	return Result;
}
