// compile: gcc foo.c -lwiringPi -lm -lcrypt -lpthread -lrt

#include <stdio.h>
#include <errno.h>

#include <wiringPi.h>
#include <wiringSerial.h>

int main()
{
    char* device = "/dev/ttyS0";
    int baud = 9600;
    int serial_port = serialOpen(device, baud);
    char data;

    if (serial_port < 0)
    {
	perror("Unable to open serial device.\n");
	return 1;
    }

    while(1)
    {
	if (serialDataAvail(serial_port))
	{
	    data = serialGetchar(serial_port);
	    printf("%c", data);
	}
    }
    return 0;
}
