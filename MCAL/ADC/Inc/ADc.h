
#ifndef MCAL_ADC_INC_ADC_H_
#define MCAL_ADC_INC_ADC_H_
#include"stdint.h"

void ADC_vidInit(void);
uint16_t ADC_u16ReadChannel(uint8_t channel);

#endif /* MCAL_ADC_INC_ADC_H_ */
