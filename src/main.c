#include <avr/io.h>
#include"util/delay.h"
#include "LCD.h"
#include  "Keypad.h"
#include "Common_Macros.h"
#include "DC_MOTOR.h"



int main(){


      LCD_init();
      LCD_motor();


    init_phasecorrect();
    init_used_pins();


      signed int  MOTOR_SPEED=0;
      unsigned char state=OFF;
      unsigned char direction=NO_DIR;




     LCD_speed_update(MOTOR_SPEED);
     LCD_state_update(state);
     LCD_direction_update(direction);


    unsigned int array[3]; // we have maximum spped build up of 3 numbers Only
    unsigned int*pointer=&array[0]; // we made a pointer 
    unsigned int top=-1;

    unsigned char key;

while(1){

	key=KYP_press();

          if(key < 10){

        	 if(top==2){

        		 LCD_ClearScreen();
        		 LCD_write_string("INVALID!");
        		 _delay_ms(2000);
        		 LCD_ClearScreen();
        		 LCD_motor();
        		 LCD_speed_update(MOTOR_SPEED);
        		 LCD_state_update(state);
        		 LCD_direction_update(direction);
        		 top=-1;

        	 }
        	 else {
        		 top++;
        		 pointer[top]=key;
        	 }

          }




          if(key=='=' && state==ON){

        	  if(top==-1){

        		  LCD_ClearScreen();
        		  LCD_write_string("ENTER SPEED !");
        		  _delay_ms(2000);
        		  LCD_ClearScreen();
        		  LCD_motor();
        		  LCD_speed_update(MOTOR_SPEED);
        		  LCD_state_update(state);
        		  LCD_direction_update(direction);

        	  }
        	  else if(top==0) {

        		  MOTOR_SPEED=pointer[top];
        		  top--;
        	  }

        	  else if(top==1){
        		  MOTOR_SPEED=(pointer[top-1]*10)+pointer[top];
        		  top-=2;
        	  }

        	  else if(top==2){
        		  MOTOR_SPEED=(pointer[top-2]*100)+(pointer[top-1]*10)+pointer[top];
        		  top-=3;
        	  }




        	  if(MOTOR_SPEED==0){
        		  state=OFF;
        		  direction=NO_DIR;
                  LCD_speed_update(MOTOR_SPEED);
                  LCD_state_update(state);
                  LCD_direction_update(direction);
                  dutycycle_config(MOTOR_SPEED);
        	  }

        	  else if(MOTOR_SPEED>100){

        		  LCD_ClearScreen();
        		  LCD_displayinteger(MOTOR_SPEED);
        		  LCD_write_string("%ISNT ALLOWED!");
        		  _delay_ms(2000);
        		  LCD_write_string("RESTARTING MOTOR...");
        		  _delay_ms(2000);
        		  LCD_ClearScreen();
        		  LCD_motor();
        		  clock_wise();
        		  MOTOR_SPEED=20;
        		  state=ON;
        		  direction=CW;
        		  LCD_speed_update(MOTOR_SPEED);
        		  LCD_state_update(state);
                  LCD_direction_update(direction);
                  dutycycle_config(MOTOR_SPEED);

        	  }
        	  else if(MOTOR_SPEED<=100){

        		  LCD_speed_update(MOTOR_SPEED);
        		  dutycycle_config(MOTOR_SPEED);

        	  }
          }




		   if(key=='C'){

			   if(state==OFF){


		   	        clock_wise();
                     top=-1;

		   	       MOTOR_SPEED=20;
		   	       state=ON;
		   	       direction=CW;



		   	       LCD_speed_update(MOTOR_SPEED);
		   	       LCD_state_update(state);
		   	       LCD_direction_update(direction);
		   	       dutycycle_config(MOTOR_SPEED);
			        }

			   else if(state==ON){

                           top=-1;

				   	   	   MOTOR_SPEED=0;
				   	   	   state=OFF;
				   	   	   direction=NO_DIR;

				   	   	   LCD_speed_update(MOTOR_SPEED);
				   	   	   LCD_state_update(state);
				   	   	   LCD_direction_update(direction);
				   	   	   dutycycle_config(MOTOR_SPEED);

			   }
		   }




		   if(key=='*' && state==ON){

		   	   top=-1;


				anti_clock_wise();


		   	   direction=ACW;

		       LCD_direction_update(direction);

		   }

		   if(key=='/' && state==ON){

		       top=-1;
			clock_wise();


		   	   direction=CW;

		      LCD_direction_update(direction);

		   }



		   if(key=='+' && MOTOR_SPEED!=100 && state==ON){

		         top=-1;

		         MOTOR_SPEED+=10;

		         if(MOTOR_SPEED <=100){

		        	 LCD_speed_update(MOTOR_SPEED);

		        	 dutycycle_config(MOTOR_SPEED);
		         }
		         else if(MOTOR_SPEED>100){

		        	 LCD_ClearScreen();
		        	 LCD_displayinteger(MOTOR_SPEED);
		        	 LCD_write_string("%ISNT ALLOWED");
		        	 _delay_ms(2000);
		        	 LCD_ClearScreen();
		        	 MOTOR_SPEED-=10;
		        	 LCD_motor();
		        	 LCD_speed_update(MOTOR_SPEED);
		        	 LCD_direction_update(direction);
		        	 LCD_state_update(state);
		        	 dutycycle_config(MOTOR_SPEED);

		         }

		   }



		   if(key=='-' && MOTOR_SPEED!=0 && state==ON){


		          top=-1;

		   	      MOTOR_SPEED-=10;

		   	      if(MOTOR_SPEED > 0){
		   	    	LCD_speed_update(MOTOR_SPEED);

		   	    	dutycycle_config(MOTOR_SPEED);
		   	      }

		   	      else if(MOTOR_SPEED==0){

		   	    	  state=OFF;
		   	    	  direction=NO_DIR;
		   	    	  LCD_speed_update(MOTOR_SPEED);
		   	    	  LCD_state_update(state);
		   	    	  LCD_direction_update(direction);
		   	    	  dutycycle_config(MOTOR_SPEED);

		   	      }
		   	      else if(MOTOR_SPEED<0){

		   	    	 LCD_ClearScreen();
		   	    	 LCD_displayinteger(MOTOR_SPEED);
		   	    	 LCD_write_string("% ISNT ALLOWED");
		   	    	 _delay_ms(2000);
		   	    	 LCD_ClearScreen();
		   	    	 MOTOR_SPEED+=10;
		   	    	 LCD_motor();
		   	    	 LCD_speed_update(MOTOR_SPEED);
		   	         LCD_direction_update(direction);
		   	    	 LCD_state_update(state);
		   	    	 dutycycle_config(MOTOR_SPEED);

		   	      }


		   }









}//end of while

return 0;
	}//end of main





