/*
 * usrat2.c
 *
 * Created: 8/31/2019 9:54:11 PM
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
	UCSR0C &= ~(1<< USBS0);// 1 stop bit
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

int main(void)
{
    /* Replace with your application code */
	
	usart_init();
	
	unsigned char data = usart_receive();
	unsigned char encrypted_data;
    while (data != '\r'){
		if((65 <= data && 90 >= data) || (97 <= data && 122 >= data) ){
			encrypted_data = data + 3 ;
			if((encrypted_data > 90 && encrypted_data < 97) || (encrypted_data > 122)){
				encrypted_data = encrypted_data - 26 ;
			}
		}else{
			encrypted_data = data;
		}
		usart_send(encrypted_data);
		data = usart_receive();
	} 
		
}

