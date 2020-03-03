/*
 * i2c.h
 *
 *  Created on: Feb 12, 2020
 *      Author: MOhamed ALMALKY
 */

#ifndef HAL_I2C_INC_I2C_H_
#define HAL_I2C_INC_I2C_H_

#include "I2Cconfg.h"


void I2C_init (void);
void I2C_STOP(void);
uint8_t I2C_START(void);


uint8_t I2C_READ_NOT_ACK(void);
uint8_t I2C_TRANSMATE(uint8_t address , uint8_t*data , uint16_t length);
uint8_t  i2c_Recevie(uint8_t address , uint8_t*data ,uint8_t length);

uint8_t I2C_MASTER_Read_data(void);
uint8_t  I2C_MASTER_WRITE(uint8_t data);
void I2C_WRITE_address(uint8_t data);
void I2C_read_address(uint8_t data);



uint8_t I2C_SLAVE_Init(uint8_t adresse);
uint8_t I2C_Slave_listen_READ();
uint8_t I2C_Slave_listen_WRITE();
int8_t I2C_SLAVE_READ(void);
void I2C_SLAVE_WRITE(uint8_t data);

#endif /* HAL_I2C_INC_I2C_H_ */
