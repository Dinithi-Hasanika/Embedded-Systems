#include <avr/io.h>

#include <util/delay.h>

int main(void)
{
	/* Replace with your application code */
	
	
	TCCR0A = (1<< WGM01) | (1<< WGM00);// fast_pwm
	TCCR0A |= (1<< COM0A1) ;// non inverting
	DDRD |= (1<<6);
	TCCR0B = 0X05; //prescaler_64
	while(1){
	unsigned char i ;
	for(i=255;i>0;i--){
	OCR0A = i;
	_delay_ms(100);
	}
	 
	
	
	
	}
}

