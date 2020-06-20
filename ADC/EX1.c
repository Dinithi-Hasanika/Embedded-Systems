/*
 * adc_ex1.c
 *
 * Created: 8/14/2019 4:08:34 PM
 * Author : DINITHI
 */ 

#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */

	DDRC &= ~(1<<1); // input
	DDRD = 0Xff; // Output
	ADCSRA |= (1<<ADEN);//enable ADC -setting this to 0 will disable even conversion in the process
	ADCSRA |= (1<<ADPS0);// select conversion speed 128(111)
	ADCSRA |= (1<<ADPS1);// select conversion speed 128(111)
	ADCSRA |= (1<<ADPS2);// select conversion speed 128(111)
	ADMUX |= (1<<REFS0);// set reference voltage AVCC with external capacitor at AREF pin bit 6 to 1
        ADMUX &= ~(1<<REFS1);// set reference voltage AVCC with external capacitor at AREF pin bit 7 to 0
	ADMUX |= (1<<ADLAR);//left justified
	ADMUX |= (1<<0);// selected ADC1 channel as input
while(1){
	ADCSRA |= (1<<ADSC);// start conversion bit set to 1
	
	while((ADCSRA & (1<<ADIF))==0){}// loop while the conversion completes and data registers updated
		
		ADCSRA |= (1<<ADIF);// conversion completes and data registers are updated
		PORTD = ADCH;
           
   }

}