/*
 * scr.c
 *
 *  Created on: Sep 23, 2019
 *      Author: ALMALKY
 */
#include "../inc/UART.h"

#include"avr/io.h"

#include "../../../common/Bit_op.h"

void UART_Init(void)
{
  // Set BaudRate -> 9600/16MhZ
  UBRRL = 102;
  UBRRH = 0;
  // Set Frame Format -> 8 data, 1 stop, No Parity
  UCSRC = 0x86;
  // Enable RX and TX
  UCSRB = 0x18;

}
void UART_TRANSMIT(uint8_t data )
{
	while(!(UCSRA&(1<<5))); //buffer is empty
	UDR = data ;
}

uint8_t UART_READ(void)
{
  uint8_t Result;
  // Wait until Reception Complete
  while((UCSRA&0x80) == 0x00);
  Result = UDR;
  /* Clear Flag */
  Set_Bit(UCSRA,7);
  return Result;

}

