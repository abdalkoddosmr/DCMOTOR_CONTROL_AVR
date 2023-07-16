


#include "DC_MOTOR.h"

#include "LCD.h"
#include  "Common_Macros.h"
#include  "Keypad.h"


void init_phasecorrect(void){

	TIMER0_CONTROL_Register =0b01110101;  //phase correct mode,1024 prescaling,inverted mode

	SET_BIT(DDRB,PB3);                   // set OC0 as output pin (pinB 3) OR DDRB|=(1<<PB3)


}




void dutycycle_config(unsigned char desiredDutycycle){


	TIMER0_COMPAREMATCH_Register=(255-((255/100)*desiredDutycycle));

}

void init_used_pins(void){

	SET_BIT(DDRB,PB4);                  // pinB 4 as output
	SET_BIT(DDRB,PB5);                  // pinB 5 as output

}

void clock_wise(void){

	SET_BIT(PORTB,PB5);
	CLEAR_BIT(PORTB,PB4);
}




void anti_clock_wise(void){

	SET_BIT(PORTB,PB4);
	CLEAR_BIT(PORTB,PB5);
}


void LCD_motor (void){


	LCD_write_string("STATE:"); // Normally at first row and first column

	LCD_CURSOR_position(1,0);

	LCD_write_string("SPEED:");

	LCD_CURSOR_position(1,11);

	LCD_write('%');


}


void LCD_speed_update(unsigned int speed){


	    LCD_CURSOR_position(1,9);
		LCD_write(' ');
		LCD_CURSOR_position(1,8);
	    LCD_write(' ');
	    LCD_CURSOR_position(1,7);
	    LCD_displayinteger(speed);

}

void LCD_direction_update(unsigned char direction){


	    if(direction==ACW){
			LCD_CURSOR_position(0,7);
			LCD_write_string("ACW");
		}

		if(direction==CW){

			LCD_CURSOR_position(0,9);
			LCD_write(' ');
			LCD_CURSOR_position(0,7);
			LCD_write_string("CW");
		}

		if(direction==NO_DIR){

			LCD_CURSOR_position(0,7);
			LCD_write_string("   ");
		}
}

void LCD_state_update(unsigned char state){

	if(state==ON){

			LCD_CURSOR_position(0,13);
			LCD_write(' ');
			LCD_CURSOR_position(0,11);
			LCD_write_string("ON");
		}

		if(state==OFF){

			LCD_CURSOR_position(0,11);
			LCD_write_string("OFF");
		}



}































