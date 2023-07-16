#ifndef keybad
#define keybad

#include <avr/io.h>
#include <util/delay.h>

//typedef unsigned char uint8;

#define nC 4
#define nR 4

#define KEYPAD_PRT PORTA
#define KEYPAD_PIN PINA
#define KEYPAD_DDR DDRA 

unsigned char KYP_press(void);

#endif 
