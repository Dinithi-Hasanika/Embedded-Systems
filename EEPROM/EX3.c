#include <avr/io.h>

//header to enable data flow control over pins


#include <util/delay.h>

//header to enable delay function in program



#define    E   5

//giving name “enable”  to 5th pin of PORTD, since it Is connected to LCD enable pin

#define RS  6

//giving name “registerselection” to 6th pin of PORTD, since is connected to LCD RS pin



void send_a_command(unsigned char command);

void send_a_character(unsigned char character);

void send_a_string(char *string_of_characters);

int main(void)

{

	DDRB = 0xFF;

	//putting portB and portD as output pins

	DDRD = 0xFF;

	_delay_ms(50);//giving delay of 50ms

	int key=0;//allocating integer to reset the LCD once it reaches its display limit

	int keypressed=0;//integer for storing matrix value

	

	send_a_command(0x01); //Clear Screen 0x01 = 00000001

	_delay_ms(50);

	send_a_command(0x38);//telling lcd we are using 8bit command /data mode

	_delay_ms(50);

	send_a_command(0b00001111);//LCD SCREEN ON and courser blinking

	

	send_a_string("PRESS A KEY");//displaying a string

	send_a_command(0x80 + 0x40 +0);// moving courser to second line of LCD

	DDRC=0xF0;//taking column pins as input and row pins as output

	_delay_ms(1);

	PORTC=0x0F;// powering the row ins

	_delay_ms(1);

	

	while(1)

	{

		if (PINC!=0b11110000)//in any of column pins goes high execute the loop

		{

			_delay_ms(5);

			keypressed = PINC;//taking the column value into integer

			DDRC^=0b11111111;//making rows as inputs and columns as ouput

			_delay_ms(1);

			PORTC ^= 0b11111111;//powering columns

			_delay_ms(1);

			

			keypressed |=PINC;taking row value and OR ing it to column value

			

			if (keypressed==0b00010001)

			{

				send_a_string("1");//if row1 and column1 is high show “1”

				key++;

			}

			if (keypressed==0b00010010)

			{

				send_a_string("4");// if row1 and column2 is high show “4”

				key++;

			}

			if (keypressed==0b00010100)

			{

				send_a_string("7");// if row1 and column3 is high show “7”

				key++;

			}

			if (keypressed==0b00011000)

			{

				send_a_string("*");//if row1 and column4 is high show “*”

				key++;

			}

			

			if (keypressed==0b00100001)

			{

				send_a_string("2");// if row2 and column1 is high show “2”

				key++;

			}

			if (keypressed==0b00100010)

			{

				send_a_string("5");// if row2 and column2 is high show “5”

				key++;

			}

			if (keypressed==0b00100100)

			{

				send_a_string("8");// if row2 and column3 is high show “8”

				key++;

			}

			if (keypressed==0b00101000)

			{

				send_a_string("0");// if row2 and column4 is high show “0”

				key++;

			}

			

			

			

			if (keypressed==0b01000001)

			{

				send_a_string("3");

				key++;

			}

			if (keypressed==0b01000010)

			{

				send_a_string("6");

				key++;

			}

			if (keypressed==0b01000100)

			{

				send_a_string("9");

				key++;

			}

			if (keypressed==0b01001000)

			{

				send_a_string("#");

				key++;

			}

			

			

			

			if (keypressed==0b10000001)

			{

				send_a_string("A");

				key++;

			}

			if (keypressed==0b10000010)

			{

				send_a_string("B");

				key++;

			}

			if (keypressed==0b10000100)

			{

				send_a_string("C");

				key++;

			}

			if (keypressed==0b10001000)

			{

				send_a_string("D");

				key++;

			}

			keypressed=0;//after showing integer erasing the row column memory

			DDRC ^=0b11111111;//shifting input and power port

			_delay_ms(1);

			PORTC ^= 0b11111111;//powering row pins of keypad

			_delay_ms(220);

			

		}

		if (key==16)//if 16 characters are shown on LCD

		{

			send_a_command(0x01);//clear lcd

			send_a_string("PRESS A KEY");//display string

			send_a_command(0x80 + 0x40 +0);//move courser to second line.

			key=0;

		}

	}

	

}



void send_a_command(unsigned char command)

{

	PORTC = command;

	PORTD &= ~ (1<<RS); //putting 0 in RS to tell lcd we are sending command

	PORTD |= 1<<E; //telling lcd to receive command /data at the port

	_delay_ms(50);

	PORTD &= ~1<<E;//telling lcd we completed sending data

	PORTC= 0;

}



void send_a_character(unsigned char character)

{

	PORTC= character;

	PORTD |= 1<<RS;//telling LCD we are sending data not commands

	PORTD |= 1<<E;//telling LCD to start receiving command/data

	_delay_ms(50);

	PORTD &= ~1<<E;//telling lcd we completed sending data/command

	PORTC = 0;

}

void send_a_string(char *string_of_characters)

{

	while(*string_of_characters > 0)

	{

		send_a_character(*string_of_characters++);

	}

}