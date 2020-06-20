/*
 * knight_rider_timer.c
 *
 * Created: 7/13/2019 3:56:34 PM
 * Author : DINITHI
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define BLINK 100
#include <avr/interrupt.h>

int main(void)
{
    /* Replace with your application code */
	DDRB = 0xFF ;
	
	TCNT1 = 3036;
	
	TCCR1A = 0x00;
	TCCR1B = 0x04;
	
	TIMSK1 = (1 << TOIE1) ;   // Enable timer1 overflow interrupt(TOIE1)
	sei();
	
    while (1) 
    {
		unsigned char i,j;
		for( i=0; i<= 3;i++){
			PORTB = PORTB | (1<<i);
			_delay_ms(BLINK);
			PORTB = PORTB & ~(1<<i);
			//_delay_ms(BLINK);
			
		}
		
		for( j=2; j>= 1;j--){
			PORTB = PORTB | (1<<j);
			_delay_ms(BLINK);
			PORTB = PORTB & ~(1<<j);
			//_delay_ms(BLINK);
			
		}
    }
}

ISR(TIMER1_OVF_vect){
	PORTB = PORTB ^ (1<<5);
	TCNT1 = 3036;
}
