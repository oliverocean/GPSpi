import time
import serial

ser = serial.Serial('/dev/ttyS0', baudrate=9600, timeout=3)

while 1:
    x=ser.readline()
    print(x)
