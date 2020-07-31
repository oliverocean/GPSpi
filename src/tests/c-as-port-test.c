// gcc -o foo foo.c -lwiringPi -lcrypt -lpthread -lrt -lm

#include <stdio.h>
#include <stdlib.h>

#include <wiringPi.h>
#include <wiringSerial.h>

#define GPIO_TXD 15
#define GPIO_RXD 16

int main (void)
{
	printf("> start:\n");

	wiringPiSetup();
	pinMode(GPIO_TXD, OUTPUT);
	pinMode(GPIO_RXD, INPUT);

	printf("> enabling txd...");
	__asm("mov x0, 15"); // set pin
	__asm("mov x1, 1"); // set value HIGH
	__asm("bl digitalWrite");
	printf(" enabled!\n");

	printf("> enabling rxd...");
	__asm("mov x0, 16"); // set pin
	__asm("mov x1, 1"); // set value HIGH
	__asm("bl digitalWrite");
	printf(" enabled!\n");

	printf("start reading serial device...\n");

	char* device = "/dev/ttyS0";
	int baud = 9600;
	int serial_port = serialOpen(device, baud);
	char data;

	if (serial_port < 0)
	{
	    perror("Unable to open serial device.\n");
	    return 1;
	}

	int count = 0;

	while (count < 10)
	{
	    if (serialDataAvail(serial_port))
	    {	
	        printf("data available.\n");
		data = serialGetchar(serial_port);
		printf("%c", data);
	    }
	    else 
	    {
	        printf("data not available.\n");
	    }
	    count++;
	}

	printf("done reading serial device...\n");

	printf("> disabling txd...");
	__asm("mov x0, 15"); // set pin
	__asm("mov x1, 0"); // set value LOW
	__asm("bl digitalWrite");
	printf(" disabled!\n");

	printf("> disabling rxd...");
	__asm("mov x0, 16"); // set pin
	__asm("mov x1, 0"); // set value LOW
	__asm("bl digitalWrite");
	printf(" disabled!\n");

	printf("> done.\n");
	
	return 0;
}
