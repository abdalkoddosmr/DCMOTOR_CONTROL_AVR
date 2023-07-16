#ifndef DC_MOTOR
#define DC_MOTOR

#include <avr/io.h>
#include"util/delay.h"


#define   ACW        'A'
#define   CW         'W'
#define   NO_DIR     '/'
#define   ON         'N'
#define   OFF        'F'




#define TIMER0_CONTROL_Register       TCCR0
#define TIMER0_COMPAREMATCH_Register  OCR0


void dutycycle_config(unsigned char desiredDutycycle);
void init_phasecorrect(void);
void init_used_pins(void);
void clock_wise(void);
void anti_clock_wise(void);
void LCD_motor(void);
void LCD_speed_update(unsigned int speed);
void LCD_direction_update(unsigned char direction);
void LCD_state_update(unsigned char state);




#endif
