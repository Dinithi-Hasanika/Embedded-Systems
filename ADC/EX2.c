/*
 * ADC_ex2.c
 *
 * Created: 8/14/2019 11:40:44 PM
 * Author : DINITHI
 */ 

#include <avr/io.h>

unsigned char x;
unsigned char y;
int main(void)
{
    /* Replace with your application code */
	DDRC &= ~(1<<1); // INPUT
	DDRD |= (1<<0) ; // OUTput
	ADCSRA |= (1<<ADPS2);
	ADCSRA |= (1<<ADEN);
	ADCSRA |= (1<<ADIE);
	ADMUX &= ~(1<<REFS1);
	ADMUX &= ~(1<<REFS0);
	ADMUX |= (1 << MUX0);
	ADMUX |= (1<<ADLAR);
    while (1) 
    {
		ADCSRA |= (1<<ADSC);

		while((ADCSRA & (1<<ADIF))==0){}
			
			x = ADCL;
			y = ADCH;
			
            PORTD = ADCH;
			
           ADCSRA |= (1<<ADIF);
    }
}

