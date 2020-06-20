/*
 * eeprom2.c
 *
 * Created: 9/8/2019 5:12:59 PM
 * Author : DINITHI
 */ 

#include <avr/io.h>
void usart_init(void){
	int baud_rate = 9600; // BAUD RATE
	int x = (int)(1000000/9600)- 1; // value to be loaded to UBRR
	UBRR0H = x >> 8 ; // value loaded to UBRR
	UBRR0L = x;// value loaded to UBRR
	UCSR0B = (1<< RXEN0) | (1<< TXEN0); //enable receiver and transmitter
	UCSR0C &= ~(1<< UMSEL01);// Set asynchronous mode
	UCSR0C &= ~(1<< UMSEL00);
	UCSR0C &= ~(1<< USBS0);// 1 stop bit -- if 2 then set to 1
	UCSR0C |= (3<< UCSZ00);// 8 bit data
}
void usart_send(unsigned char data){
	while(!(UCSR0A &&  (1<< UDRE0))){}//Monitor the UDRE0 bit of the UCSR0A register to make sure UDR0 is ready for the next byte.when ready UDRE0 is high
	UDR0 = data;
	
}
unsigned char usart_receive(void){
	while(!(UCSR0A &&  (1<< RXC0))){}//RXC0 flag bit of the UCSR0A register is monitored for a HIGH to see if an entire character has been received yet
	return UDR0;
	
}

void EEPROMwrite(unsigned int address, char data){
	while(EECR & (1<<EEPE));
	EEAR = address;
	EEDR = data;
	EECR |= (1<< EEMPE);
	EECR |= (1<< EEPE);
}

char EEPROMread(unsigned int address){
	while(EECR & (1<<EEPE));
	EEAR = address;
	EECR |= (1<< EERE);
    return EEDR;
}

int main(void)
{
    /* Replace with your application code */
	
	usart_init();
	int addr = 0;
	char data ;

    while (1){
		
			char data = usart_receive();
			EEPROMwrite(addr,data);
			addr++;
			//usart_send(data);

		
		
	}
}

