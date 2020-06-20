/*
 * pwm_ex1.c
 *
 * Created: 7/22/2019 8:40:23 AM
 * Author : DINITHI
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>


int main(void)
{
    /* Replace with your application code */
	
	
	TCCR0A = (1<< WGM01) | (1<< WGM00);// fast pwm
	TCCR0A |= (1<< COM0A1) ;// non inverting
	//TCCR0A = 131;
	//TCCR0B = 11;
	
	OCR0A = 127;// duty cycle 50%
	TCCR0B = 0X03; //prescaler 64
	
	DDRD |= (1<<6);
	
    while (1) 
    {
    }
}

