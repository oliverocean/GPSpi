### GPSpi Prototype A
Gathers GPS data from a physical sensor and displays as character strings on a console.

> ![Prototype A](/img/IMG_2617-450px.jpg)

### Features
- Status LED: "actively receiving data"
- Physical reset/kill switch

### Components
- Host machine: [Raspberry Pi 3](https://www.raspberrypi.org/documentation/hardware/raspberrypi/README.md) (model B+)
- Operating system: Ubuntu Server 18.04 (64-bit) for Raspberry Pi, an [AArch64](https://archlinuxarm.org/packages/aarch64/linux-aarch64) package (64-bit OS needed for ARMv8 ISA)
- GPS sensor: [MTK3339](https://learn.adafruit.com/adafruit-ultimate-gps/overview) (Adafruit) with 28dB external active [GPS antenna](https://www.adafruit.com/product/960)

### Software
- Written in C and assembly language
- Uses the [ARMv8](https://developer.arm.com/documentation/den0024/a/an-introduction-to-the-armv8-instruction-sets) instruction set architecture
- Assembly language instructions embedded into C code using [asm](https://gcc.gnu.org/onlinedocs/gcc/Using-Assembly-Language-with-C.html), a C language extension
- UART serial communication enabled using the [wiringPi](http://wiringpi.com/) library

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

### How it works
**Space Vehicle to GPS Sensor**</br>
- GPS [satellites](https://en.wikipedia.org/wiki/Global_Positioning_System#Space_segment) broadcast RF [signals](https://en.wikipedia.org/wiki/Global_Positioning_System#More_detailed_description) which are received by the GPS sensor
- The GPS sensor has built in firmware which parses RF signals into the [NMEA](https://en.wikipedia.org/wiki/NMEA_0183) protocol
- NMEA data is available via Tx/Rx pins of the GPS sensor, formatted as "sentences", each starting with a '$' delimiter

**GPS Sensor to Raspberry Pi**</br>
- Tx/Rx pins of the GPS sensor are physically wired to GPIO pins on the Raspberry Pi
- Linux serial communications *---> placeholder: add details of kernal/user space i/o restrictions*
- *placeholder: UART details*
- GPIO pins on the Raspberry Pi can be accessed using the Wiring Pi library
- *placeholde: next steps*

---

## NOTE: draft/in-progress/incomplete documentation below 

### Hardware Setup

#### Headers
- initial testing process with multimeter to verify correctly soldered on gps board

#### Breadboard
- physical rpi breakout board and breadboard wiring configuration (perhaps a Fritizing diagram with all pins, led, kill switch, etc).

### Operating System Configuration
- boot process pitfalls and kill switch usage
- serial/console configuration (systemctl masking of console on tty0, systemctl disabling gpsd, etc)

#### GPS tools
any other GPS related tools/documentation
- Test GPS data stream parsing with [gpsd](https://gpsd.gitlab.io/gpsd/index.html)

#### WiringPi library
- WiringPi is a well documented, nicely designed, easy to use library but it has been deprecated; future prototypes will not include this library
- After extensive testing, WiringPi does not appear to work with Arch Linux, thus this prototype uses Ubuntu Linux
- WiringPi includes a tool called "gpio", which is helpful for troubleshooting (basic usage included below)

### Testing 
- Hardware: initial testing process with usb/serial cable, gpsd including GPS antenna placement (line of sight to sky) - link to external references as needed
- Software: explain purpose of the included manual tests (serial, led)

### Findings
- reasons for including/excluding certain features (course project requirements) and/or for modifying initial plans, deadlines, etc)
- future features that could be added to this prototype (configurable number of lines to pull down, simple parsing of location data, automated logging, etc)
- possible issues/bugs (conflicts with gpsd, other scripts and libraries may modify gpio pin states, etc)

---



