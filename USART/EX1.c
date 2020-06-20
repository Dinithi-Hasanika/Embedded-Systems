/*
 * usart1.c
 *
 * Created: 8/31/2019 6:16:07 PM
 * Author : DINITHI
 */ 

#include <avr/io.h>

void usart_init(void){
	int baud_rate = 9600; // BAUD RATE
	int x = (int)(1000000/9600)- 1; // value to be loaded to UBRR
	UBRR0H = x >> 8 ; // value loaded to UBRR
	UBRR0L = x;// value loaded to UBRR
	UCSR0B = (1<< RXEN0) | (1<< TXEN0); //enable receiver and transmitter
	UCSR0C &= ~(1<< UMSEL0);// Set asynchronous mode
	UCSR0C &= ~(1<< USBS0);// 1 stop bit -- if 2 then set to 1
	UCSR0C |= (3<< UCSZ00);// 8 bit data
}
void usart_send(unsigned char data){
	while(!(UCSR0A &&  (1<< UDRE0))){}//Monitor the UDRE0 bit of the UCSR0A register to make sure UDR0 is ready for the next byte.
		UDR0 = data;
	
}
unsigned char usart_receive(void){
	while(!(UCSR0A &&  (1<< RXC0))){}//RXC0 flag bit of the UCSR0A register is monitored for a HIGH to see if an entire character has been received yet
		return UDR0;
}
int main(void)
{
    /* Replace with your application code */
	usart_init();
	int i;
	char dinithi[] ="dinithi E15119\n";
	for(i=0;dinithi[i] != '\0';i++){
	usart_send(dinithi[i]);
	}
	char dulanjali[] ="dulanjali E15202\n";
	for(i=0;dulanjali[i] != '\0';i++){
		usart_send(dulanjali[i]);
	}
	char roshani[] ="roshani E15208\n"; 
	for(i=0;roshani[i] != '\0';i++){
		usart_send(roshani[i]);
	}
    
}

