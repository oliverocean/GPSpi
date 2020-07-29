// gcc -o foo foo.c -lwiringPi -lcrypt -lpthread -lrt -lm

#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

#define GPIO_PIN 0

int main (void)
{
	int index = 0;

	printf("> start...\n");

	wiringPiSetup();
	pinMode(GPIO_PIN, OUTPUT);

	while (index < 4)
	{
		// digitalWrite(pin, value);
		__asm("mov x0, 0"); // set pin
		__asm("mov x1, 1"); // set value HIGH
		__asm("bl digitalWrite");
		printf("> led: on\n");
		delay(1000);

		// digitalWrite(pin, value);
		__asm("mov x0, 0"); // set pin
		__asm("mov x1, 0"); // set value LOW
		__asm("bl digitalWrite");
		printf("> led: off\n");
		delay(1000);

		index++;
	}	

	printf("> end...\n");
	
	return 0;
}
