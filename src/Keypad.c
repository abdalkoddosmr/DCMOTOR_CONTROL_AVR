#include "Keypad.h"

unsigned char KYP_press(void)
{
	unsigned char col,row;
	
	while(1)
	{
		
		for(col=0;col<nC;col++) //loop for columns
		{
			KEYPAD_PRT |= 0x0F; //enable the internal pull up resistors for the first 4 pins in PORTA --> ROW pins.
			//each time only one of the column pins will be output and the rest will be input pins include the row pins 
			KEYPAD_DDR = (0b00010000<<col); 
			KEYPAD_PRT &= (~(0b00010000<<col)); // clear the column which is the output pin in this trace 
			for(row=0;row<nR;row++) //loop for rows
			{
				if((KEYPAD_PIN & (1<<row)) == 0) //if the switch is press in this row 
				{
					_delay_ms(30);
					if((KEYPAD_PIN & (1<<row)) == 0) //if the switch is press in this row
					{
						#if (nC == 3)  
						 unsigned char keypad_4x3[nR][nC] = {'1','2','3',
															 '4','5','6',
															 '7','8','9',
															 '*','0','#'};
						while((KEYPAD_PIN & (1<<row)) == 0);
						
						return keypad_4x3[row][col];						
						
						#else
						
						unsigned char keypad_4x4[nR][nC] = {7,8,9,'/',
															4,5,6,'*',
															1,2,3,'-',
															'C',0,'=','+'};
						while((KEYPAD_PIN & (1<<row)) == 0);
						
						return keypad_4x4[row][col];												
						#endif								
					}
				}
			}
		}
	}	
}
