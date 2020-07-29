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

	printf("delaying...");
	delay(1000);
	printf(" continuing...\n");

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
