/*
 * pwm_ex3.c
 *
 * Created: 7/22/2019 4:39:51 PM
 * Author : DINITHI
 */ 

#include <avr/io.h>
#include <util/delay.h>



int main(void)
{
	/* Replace with your application code */
	
	
	TCCR0A = (1<< WGM01) | (1<< WGM00);// fast_pwm
	TCCR0A |= (1<< COM0A1) ;// non inverting
	//TCCR0A = 131;
	//TCCR0B = 11;
	
	OCR0A = 127;
	//prescaler_64
	DDRD |= (1<<6);
	while(1){
	TCCR0B = 0X04; 
	
	_delay_ms(1000);

	TCCR0B = 0X03; 
	_delay_ms(1000);

	TCCR0B = 0X02; 
     _delay_ms(1000);
	
	 TCCR0B = 0X01; 
	 _delay_ms(1000);
	}
	
	
}


