#ifndef LCD
#define LCD

#include <avr/io.h>
#include"util/delay.h"




#define LCD_DATA  PORTC
#define en        PD0
#define rw        PD1
#define rs        PD2





void LCD_init(void);
void LCD_cmd(unsigned char cmd);
void LCD_write(unsigned char data);
void LCD_CURSOR_position(unsigned char row, unsigned char cloumn);
void LCD_write_string(const char *str);
void LCD_displayinteger (unsigned int number);
void LCD_ClearScreen(void);

#endif 
