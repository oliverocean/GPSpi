from time import sleep
import wiringpi as GPIO

serial = GPIO.serialOpen('/dev/ttyS0', 9600)

while 1:
    char = GPIO.serialGetchar(serial)
    print(char)
