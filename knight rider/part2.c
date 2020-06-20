/*
 * knight_part2.c
 *
 * Created: 7/13/2019 4:29:51 PM
 * Author : DINITHI
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>


	
//	TIFR1= 0x01;
	
	
	



int main(void)
{
    /* Replace with your application code */
   DDRB |= (1<<5);
   TCNT1 = 63974;
   
   TCCR1A = 0x00;
   TCCR1B = 0x04;
   
   TIMSK1 = (1 << TOIE1) ;   // Enable timer1 overflow interrupt(TOIE1)
   sei();
   
   while (1)
   {
	   
	   
	//   PORTB = PORTB ^ (1<<5);
	   
	   
	  
   }
}

ISR(TIMER1_OVF_vect){
	PORTB = PORTB ^ (1<<5);
	TCNT1 = 63974;
}
