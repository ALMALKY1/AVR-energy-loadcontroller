/*
 * uart.h
 *
 *  Created on: Sep 23, 2019
 *      Author: MELMA
 */

#ifndef MCAL_UART_INC_UART_H_
#define MCAL_UART_INC_UART_H_
#include"stdio.h"
#include "../UARTconfg/UARTconfg.h"

#define MYUBRR  (FOCSC/16(BAUD))-1

void UART_Init(void);
void UART_TRANSMIT(uint8_t data );
uint8_t UART_READ(void);

/*

void UART_string(uint8_t*string);
uint8_t* UART_READ_string_servo(void);
uint8_t *UART_READ_string_angle(void);
uint8_t*UART_READ_string_servo_opition(void);
*/

#endif /* MCAL_UART_INC_UART_H_ */
