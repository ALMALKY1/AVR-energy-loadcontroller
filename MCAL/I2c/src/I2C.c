
/*

 * i2c.c
 *
 *  Created on: Feb 11, 2020
 *      Author: Mohamed  Mahmoud ALMALKY
 */
#include <avr/io.h>

#include "../inc/i2c.h"


#ifndef F_CPU
#define F_CPU 12000000UL
#endif

#define F_SCL 100000UL
#define Prescaler 4
#define TWBR_value ((((F_CPU/F_SCL)/Prescaler)-16)/2) //SCL 100KH


//MASRTER TRANSMATTE ___ WRITE MODE

void I2C_init (void)
{
	TWSR = (1<<TWPS0)|(1<<TWPS1); //4 PRESCALLE
	TWBR = (uint8_t)TWBR_value ;
}

uint8_t I2C_START(void)
{
	//reset TW_CONTROL_REGISTER
	TWCR=0;
	//transmit  START condition
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	//wait for end transmission
	while(!(TWCR & (1 << TWINT)));
	//check if the start condition was successfully transmitted
	if((TWSR & 0xF8 )!= TW_START) return 0;
	return 1 ;
}



//MASTER MODE



void I2C_WRITE_address(uint8_t adress )
{
    TWDR=adress + I2C_Write_MODE;    // Address and write instruction
    TWCR=(1<<TWINT)|(1<<TWEN);    // Clear TWI interrupt flag,Enable TWI
    while (!(TWCR & (1<<TWINT))); // Wait till complete TWDR byte received
    while((TWSR & 0xF8)!= TW_MT_SLA_ACK);  // Check for the acknoledgement
}

void I2C_read_address(uint8_t adress)
{
    TWDR=adress+I2C_READ_MODE;    // Address and read instruction
    TWCR=(1<<TWINT)|(1<<TWEN);    // Clear TWI interrupt flag,Enable TWI
    while (!(TWCR & (1<<TWINT))); // Wait till complete TWDR byte received
    while((TWSR & 0xF8)!= 0x40);  // Check for the acknoledgement
}





uint8_t  I2C_MASTER_WRITE(uint8_t data){

	//load DATA INTO REGISTER
	TWDR = data ;

	// START transmission
	TWCR = (1<<TWINT) | (1<<TWEN) ;

	// Wait for TWINT flag set in TWCR Register
	while(!(TWCR & (1 << TWINT)));

	//check  device has ACK Data done
	if((TWSR&0xF8) != TW_MT_DATA_ACK) return 1 ;

	return 0 ;
}



//MASTWER READ MODE

uint8_t I2C_MASTER_Read_data(void)
{
    TWCR=(1<<TWINT)|(1<<TWEN);    // Clear TWI interrupt flag,Enable TWI
    while (!(TWCR & (1<<TWINT))); // Wait till complete TWDR byte transmitted
    while((TWSR & 0xF8) != 0x58); // Check for the acknoledgement

    return TWDR ;
}




//slave Init

uint8_t I2C_SLAVE_Init(uint8_t adresse){

	// load address
	TWAR=adresse ;
	// transmit ADRESS
	  TWCR=(1<<TWEN)|(1<<TWEA)|(1<<TWINT);
	// delay for transmission
	while(!(TWCR & (1 << TWINT)));

	//check if  the device has ACK READ OR WRITE  MODE
	while((TWSR & 0xF8)!= 0x08);
	uint8_t twst = TWSR & 0xF8 ;
	if((twst !=TW_MT_SLA_ACK && twst!= TW_MR_SLA_ACK))return 1 ;
	return 0;
}

//Slave Receiver Mode

uint8_t I2C_Slave_listen_READ(){


		uint8_t status ;
		while(!(TWCR&(1<<TWINT)));
		status=TWSR&0xF8;
		 while(status!= 0x60) // Loop till correct acknoledgement have been received
		 {
		        // Get acknowlegement, Enable TWI, Clear TWI interrupt flag
		        TWCR=(1<<TWEA)|(1<<TWEN)|(1<<TWINT);
		        while (!(TWCR & (1<<TWINT)));  // Wait for TWINT flag
		        return 0;
		 }
		 return 1 ;
}



int8_t I2C_SLAVE_READ(void)
{
	  TWCR= (1<<TWINT)|(1<<TWEA)|(1<<TWEN);
	    while (!(TWCR & (1<<TWINT)));    // Wait for TWINT flag
	    while((TWSR & 0xF8)!=0x80);        // Wait for acknowledgement
	   return TWDR;                    // Get value from TWDR

}


//slave transmater mode


uint8_t I2C_Slave_listen_WRITE(){

		uint8_t status ;
		while(!(TWCR&(1<<TWINT)));
		 return 1 ;
		status=TWSR&0xF8;
		 while(status!= 0xA8)  // Loop till correct acknoledgement have been received
		    {
		        // Get acknowlegement, Enable TWI, Clear TWI interrupt flag
		        TWCR=(1<<TWEA)|(1<<TWEN)|(1<<TWINT);
		        while (!(TWCR & (1<<TWINT)));  // Wait for TWINT flag
		        return 0;
		    }

		 return 1 ;

	}


//slave write

void I2C_SLAVE_WRITE(uint8_t data) // Function to write data
{
    TWDR= data;              // Fill TWDR register whith the data to be sent
    TWCR= (1<<TWEN)|(1<<TWINT);   // Enable TWI, Clear TWI interrupt flag
    while((TWSR & 0xF8) != 0xC0); // Wait for the acknowledgement
}





//slave read

uint8_t I2C_READ_ACK(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)| (1<<TWEA) ;

	// Wait for TWINT flag set in TWCR Register
	  while (!(TWCR & (1 << TWINT)));

	  return TWDR  ;
}

uint8_t I2C_READ_NOT_ACK(void)
{

	TWCR = (1<<TWINT)|(1<<TWEN);
	// Wait for TWINT flag set in TWCR Register
		  while (!(TWCR & (1 << TWINT)));
		  return TWDR  ;

}





uint8_t I2C_TRANSMATE(uint8_t address , uint8_t*data , uint16_t length)
{


	for(uint8_t i ; i<length ; i++)
	{
		if(I2C_MASTER_WRITE(data[length])){

		return 1 ;
		}
	}

	I2C_STOP();
return 0 ;

}

uint8_t i2c_Recevie(uint8_t address , uint8_t*data ,uint8_t length)
{
	for(uint8_t i=0; i<length-1 ; i++)
		{
			data[length]=I2C_READ_ACK();
		}
	 data[length-1]=I2C_READ_NOT_ACK();
	 I2C_STOP();

				return 0 ;
		}


void I2C_STOP(void){
		TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
		while(!(TWCR & (1 << TWINT)));
}


void I2C_repeated_start(void)
{
// Clear TWI interrupt flag, Put start condition on SDA, Enable TWI
TWCR= (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
while(!(TWCR & (1<<TWINT))); // wait till restart condition is transmitted
while((TWSR & 0xF8)!= 0x10); // Check for the acknoledgement
}





