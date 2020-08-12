from time import sleep
import wiringpi as GPIO

gpio_led = 0
gpio_txd_out = 15
gpio_rxd_in = 16

input_mode = 0
output_mode = 1

set_low = 0
set_high = 1

GPIO.wiringPiSetup()

GPIO.pinMode(gpio_led, output_mode)
GPIO.pinMode(gpio_txd_out, output_mode)
GPIO.pinMode(gpio_rxd_in, input_mode)

GPIO.digitalWrite(gpio_led, set_high)
GPIO.digitalWrite(gpio_txd_out, set_high)
GPIO.digitalWrite(gpio_rxd_in, set_low)

print("\nOpening serial port...")
serial = GPIO.serialOpen('/dev/ttyS0', 9600)

print("How much serial data is available?")
print(GPIO.serialDataAvail(serial))

print("Start read:")
count = 0
while count < 20:
    char = GPIO.serialGetchar(serial)
    print(char)
    count += 1
print("done. exiting in 3 seconds...\n")

sleep(3)
GPIO.digitalWrite(gpio_led, set_low)
GPIO.digitalWrite(gpio_txd_out, set_low)
GPIO.digitalWrite(gpio_rxd_in, set_low)
