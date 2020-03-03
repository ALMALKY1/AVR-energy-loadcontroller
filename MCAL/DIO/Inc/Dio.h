#ifndef DIO_H
#define DIO_H

#include "stdint.h"


#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

typedef enum
{
	Dio_PORTA ,
	Dio_PORTB,
	Dio_PORTC,
	Dio_PORTD
} enuPortType;

typedef enum
{
	Dio_Input = 0,
	Dio_Output
} enuPortDirection;

typedef enum
{
	Dio_Low = 0,
	Dio_High
} enuPinState;

uint8_t Dio_u8ReadPin(enuPortType Port, uint8_t Pin);
uint8_t Dio_u8ReadPort(enuPortType Port, uint8_t Control);

void Dio_vidWritePort(enuPortType Port, uint8_t Value);
void Dio_vidWritePin(enuPortType Port, uint8_t Pin, enuPinState State);

void Dio_vidSetPortDirection(enuPortType Port, enuPortDirection Direction);
void Dio_vidSetPinDirection(enuPortType Port, uint8_t Pin, enuPortDirection Direction);
#endif
