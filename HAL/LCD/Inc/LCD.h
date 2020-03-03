#ifndef LCD_H
#define LCD_H
#include "stdint.h"

/*Clears entire display*/
#define LCD_CLEAR        0b00000001
/*Entry Mode: Increment Cursor, No Shift*/
#define LCD_ENTRY_MODE   0b00000110
/*Display ON, Cursor = OFF, No Blink*/
#define LCD_DISPLAY_ON   0b00001100
/*Display OFF*/
#define LCD_DISPLAY_OFF  0b00001000
#define LCD_CURSOR_ON    0b00001110
#define LCD_CURSOR_OFF   0b00001100

#define LCD_CURSOR_BLINK_ON  0b00001111
#define LCD_CURSOR_BLINK_OFF 0b00001110
/*Function Set 8-Bit Mode, 2-Lines, Font = 5x7*/
#define LCD_FUNCTION_SET    0b00111000

#define LCD_MOVE_CURSOR      0b10000000

void LCD_vidInit(void);
void LCD_vidWriteData(uint8_t Data);
void LCD_vidPrintNumber(uint32_t Number);
void LCD_vidWriteCommand(uint8_t Command);
void LCD_vidWriteString(uint16_t * Message);
void LCD_vidGoTo(uint8_t Line, uint8_t Column);
#endif
