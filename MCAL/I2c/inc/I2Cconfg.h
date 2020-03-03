/*
 * I2Cconfg.h
 *
 *  Created on: Feb 11, 2020
 *      Author: Mohamed ALMALKY
 */

#ifndef HAL_I2C_INC_I2CCONFG_H_
#define HAL_I2C_INC_I2CCONFG_H_



//some offset
//Status for Master Transmitter Mode
#define TW_MT_ARB_LOST 0x38
#define TW_MR_ARB_LOST 0x38
#define TW_START 0x03
#define TW_REP_START 0x10
#define TW_MT_SLA_ACK 0x18
#define TW_MT_SLA_NOT_ACK  0X20
#define TW_MT_DATA_ACK 0x28
#define TW_MT_DATA_NOT_ACK 0x30
#define I2C_Write_MODE 0
#define I2C_READ_MODE 1
//Status for Master Receiver Mode

#define TW_MR_SLA_ACK 0x40
#define TW_MR_SLA_NOT_ACK 0x48
#define TW_MR_DATA_ACK 0x50
#define TW_MR_DATA_NOT_ACK 0x58


#define I2C_read 1
#define I2C_write 0




#endif /* HAL_I2C_INC_I2CCONFG_H_ */
