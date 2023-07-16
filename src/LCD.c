#include "LCD.h"
#include  "Common_Macros.h"


void LCD_init(void){

	DDRC=0xFF;    //make data port as output

	SET_BIT(DDRD,rs);
	SET_BIT(DDRD,rw);
	SET_BIT(DDRD,en);

	_delay_ms(30);

	LCD_cmd(0x0C);  //display on cursor off

	_delay_ms(1);
	LCD_cmd(0x38);  //initialization of 16x2 LCD in 8 bit mode

	_delay_ms(1);

	LCD_cmd(0x01);   //clear LCD display screen

	_delay_ms(1);

    LCD_cmd(0x02);  //return home

    _delay_ms(1);

    LCD_cmd(0x06);  //make increment in the cursor

    _delay_ms(1);

    LCD_cmd(0x80);   //go to first line and 0th position
    _delay_ms(1);
}

void LCD_cmd(unsigned char cmd){


	CLEAR_BIT(PORTD,rs);   //RS set to 0

    CLEAR_BIT(PORTD,rw);   //Rw set to 0

    LCD_DATA =cmd;         // give command address to LCD_DATA port and LCD_DATA port send to LCD

    SET_BIT(PORTD,en);     //EN set to 1

    _delay_ms(1);

    CLEAR_BIT(PORTD,en);    //EN set to 0

    _delay_ms(30);

}

void LCD_write(unsigned char data){


		SET_BIT(PORTD,rs);     //RS set to 1

	    CLEAR_BIT(PORTD,rw);   //Rw set to 0

	    LCD_DATA =data;         // give data to LCD_DATA port and LCD_DATA port send to LCD

	    SET_BIT(PORTD,en);     //EN set to 1

	    _delay_ms(1);

	    CLEAR_BIT(PORTD,en);    //EN set to 0

	    _delay_ms(30);

}

void LCD_CURSOR_position(unsigned char row, unsigned char column){


	unsigned char address=0;

	if(row==0){

		address=0x80;
	}

	else if(row==1){

		address=0xC0;
	}

	if(column<16){

		address +=column;
	}

	LCD_cmd(address);


}




void LCD_write_string(const char *str){

	unsigned char iteration=0;

	while(str[iteration] != '\0'){


		LCD_write(str[iteration]);
		iteration++;
  }



}


void LCD_displayinteger (unsigned int number){

   char ch[16];
   itoa(number,ch,10);
   LCD_write_string(ch);


}


void LCD_ClearScreen(void)
{
	LCD_cmd(0x01);
}




