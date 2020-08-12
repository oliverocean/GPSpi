// gcc -o led led.c -lwiringPi -lcrypt -lpthread -lrt -lm

#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

#define GpioPin 0

int main (void)
{
	int index = 0;

	printf("> start led test\n");

	wiringPiSetup();
	pinMode(GpioPin, OUTPUT);

	while (index < 4)
	{
		digitalWrite(GpioPin, HIGH);
		printf("> led: on\n");
		delay(1000);

		digitalWrite(GpioPin, LOW);
		printf("LED off...\n");
		delay(1000);

		index++;
	}

	printf("> end led test\n");
	
	return 0;
}
