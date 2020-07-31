// gcc -o foo foo.c -lwiringPi -lcrypt -lpthread -lrt -lm

#include <stdio.h>
#include <stdlib.h>

#include <wiringPi.h>
#include <wiringSerial.h>

#define GPIO_LED 0 
#define GPIO_TXD 15
#define GPIO_RXD 16
#define INPUT_MODE 0
#define OUTPUT_MODE 1
#define ALT5_MODE 2

void blink_led(void);

int main (void)
{
	printf("\n---[ Enable GPS Sensor ]---\n");

	wiringPiSetup();
	pinMode(GPIO_TXD, ALT5_MODE);
	pinMode(GPIO_RXD, ALT5_MODE);
	pinMode(GPIO_LED, OUTPUT_MODE);

	printf(" > Enabling TxD...");
	__asm("mov x0, 15"); // select pin
	__asm("mov x1, 1"); // set value HIGH (enable)
	__asm("bl digitalWrite");
	printf(" enabled!\n");

	printf(" > Enabling RxD...");
	__asm("mov x0, 16"); // select pin
	__asm("mov x1, 1"); // set value HIGH (enable)
	__asm("bl digitalWrite");
	printf(" enabled!\n");

	printf("\n---[ Read GPS Data ]---\n");

	char* device = "/dev/ttyS0";
	int baud = 9600;
	int serial_port = serialOpen(device, baud);
	char data;

	if (serial_port < 0)
	{
	    perror("Unable to open serial device.\n");
	    return 1;
	}

	int line_count = 0;

	while (line_count < 20)
	{
	    if (serialDataAvail(serial_port))
	    {	
		data = serialGetchar(serial_port);
		printf("%c", data);
		if (data == 36) 
		{ 
		    line_count++; 
		    blink_led();
		}
	    }
	}

	printf("\n\n---[ Disable GPS Sensor ]---\n");

	printf(" > Disabling TxD...");
	__asm("mov x0, 15"); // set pin
	__asm("mov x1, 0"); // set value LOW (disable)
	__asm("bl digitalWrite");
	printf(" disabled!\n");

	printf(" > Disabling RxD...");
	__asm("mov x0, 16"); // set pin
	__asm("mov x1, 0"); // set value LOW (disable)
	__asm("bl digitalWrite");
	printf(" disabled!\n");

	printf("\n---[ Exit ]---\n\n");
	
	return 0;
}

void blink_led(void)
{
    __asm("mov x0, xzr"); // select pin
    __asm("mov x1, 1"); // set value HIGH (enable)
    __asm("bl digitalWrite");
    delay(5);
    __asm("mov x0, xzr"); // select pin
    __asm("mov x1, xzr"); // set value LOW (disable)
    __asm("bl digitalWrite");
}
