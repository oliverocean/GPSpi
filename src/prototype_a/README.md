### GPSpi Prototype A
Gathers GPS data from a physical sensor and displays as character strings on a console.

### Software
* Written in C and assembly language
* Uses the [ARMv8](https://developer.arm.com/documentation/den0024/a/an-introduction-to-the-armv8-instruction-sets) instruction set architecture
* Assembly language instructions embedded into C code using [asm](https://gcc.gnu.org/onlinedocs/gcc/Using-Assembly-Language-with-C.html), a C language extension
* UART serial communication enabled using the [wiringPi](http://wiringpi.com/) library

### Physical Components
* Host machine: [Raspberry Pi 3](https://www.raspberrypi.org/documentation/hardware/raspberrypi/README.md) (model B+)
* Operating system: Ubuntu Server 18.04 (64-bit) for Raspberry Pi, an [AArch64](https://archlinuxarm.org/packages/aarch64/linux-aarch64) package (64-bit OS needed for ARMv8 ISA)
* GPS sensor: [MTK3339](https://learn.adafruit.com/adafruit-ultimate-gps/overview) (Adafruit) with external GPS antenna

### Usage
~~~
% sudo ./gpio-asm

---[ Enable GPS Sensor ]---
 > Enabling TxD... enabled!
 > Enabling RxD... enabled!

---[ Read GPS Data ]---
$GPVTG,123.45,T,,M,0.78,N,0.91,K,D*2C
$GPGGA,345670.000,8976.1234,N,01234.5678,W,2,10,1.23,456.7,M,-89.7,M,0000,0000*89
$GPGSA,A,1,23,45,67,89,01,,,,,,,,1.23,4.56,7.89*09
$GPRMC,9876543.000,A,4567.8901,N,012345.8765,W,0.12,345.67,123456,,,D*88
$GPVTG,123.45,T,,M,0.78,N,0.91,K,D*2C
$GPGGA,345670.000,8976.1234,N,01234.5678,W,2,10,1.23,456.7,M,-89.7,M,0000,0000*89
$GPGSA,A,1,23,45,67,89,01,,,,,,,,1.23,4.56,7.89*09
$GPRMC,9876543.000,A,4567.8901,N,012345.8765,W,0.12,345.67,123456,,,D*88
$GPVTG,123.45,T,,M,0.78,N,0.91,K,D*2C
$GPGGA,345670.000,8976.1234,N,01234.5678,W,2,10,1.23,456.7,M,-89.7,M,0000,0000*89
$GPGSA,A,1,23,45,67,89,01,,,,,,,,1.23,4.56,7.89*09
$GPRMC,9876543.000,A,4567.8901,N,012345.8765,W,0.12,345.67,123456,,,D*88
$GPVTG,123.45,T,,M,0.78,N,0.91,K,D*2C
$GPGGA,345670.000,8976.1234,N,01234.5678,W,2,10,1.23,456.7,M,-89.7,M,0000,0000*89
$GPGSA,A,1,23,45,67,89,01,,,,,,,,1.23,4.56,7.89*09
$GPRMC,9876543.000,A,4567.8901,N,012345.8765,W,0.12,345.67,123456,,,D*88
$GPVTG,123.45,T,,M,0.78,N,0.91,K,D*2C
$GPGGA,345670.000,8976.1234,N,01234.5678,W,2,10,1.23,456.7,M,-89.7,M,0000,0000*89
$GPGSA,A,1,23,45,67,89,01,,,,,,,,1.23,4.56,7.89*09
$GPRMC,9876543.000,A,4567.8901,N,012345.8765,W,0.12,345.67,123456,,,D*88

---[ Disable GPS Sensor ]---
 > Disabling TxD... disabled!
 > Disabling RxD... disabled!

---[ Exit ]---
~~~

--- 

## Things to be documented next!
- add a features section above (high level)
- add a "requirements" section explaining reasons for including certain features (ie: course project requirements)
- add a "findings" section explaining reasons for not including certain features and/or for modifying initial plans (deadlines)
- describe initial testing process with multimeter to verify correctly soldered headers on gps board
- describe initial testing process with usb/serial cable and gpsd including GPS antenna placement (line of sight to sky) - link to external references as needed
- document physical rpi breakout board and breadboard wiring configuration (perhaps a Fritizing diagram with all pins, led, kill switch, etc).
- explain serial/console configuration (systemctl masking of console on tty0, systemctl disabling gpsd, etc)
- explain boot process pitfalls and kill switch usage
- explain how to install wiringPi and the gpio tool (and any other GPS related tools/documentation - external links as needed)
- explain purpose of the included manual tests (serial, led)
- future features that could be added to this prototype (configurable number of lines to pull down, simple parsing of location data, automated logging, etc)
- describe possible issues/bugs (conflicts with gpsd, other scripts and libraries may modify gpio pin states, etc)

---

### WiringPi library
* WiringPi is a well documented, nicely designed, easy to use library but it has been deprecated; future prototypes will not include this library
* After extensive testing, WiringPi does not appear to work with Arch Linux, thus this prototype uses Ubuntu Linux
* WiringPi includes a tool called "gpio", which is helpful for troubleshooting (basic usage included below)

### GPSD testing
* Test GPS data stream parsing with [gpsd](https://gpsd.gitlab.io/gpsd/index.html)
~~~
to do
~~~


