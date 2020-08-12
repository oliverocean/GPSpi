**Prototype 01**</br>
Gathers GPS data from a physical sensor and displays on a console.

### Software
* Written in C and assembly language
* Uses the [ARMv8](https://developer.arm.com/documentation/den0024/a/an-introduction-to-the-armv8-instruction-sets) instruction set architecture
* Assembly language instructions embedded into C code using [asm](https://gcc.gnu.org/onlinedocs/gcc/Using-Assembly-Language-with-C.html), a C language extension
* UART serial communication enabled using [wiringPi](http://wiringpi.com/)

### Configuration
* Host machine: [Raspberry Pi 3](https://www.raspberrypi.org/documentation/hardware/raspberrypi/README.md) (model B+)
* Operating system: Ubuntu Server 18.04 (64-bit) for Raspberry Pi, an [AArch64](https://archlinuxarm.org/packages/aarch64/linux-aarch64) package (64-bit OS needed for ARMv8 ISA)
* GPS sensor: [MTK3339](https://learn.adafruit.com/adafruit-ultimate-gps/overview) (Adafruit) with external GPS antenna

![MT3339 GPS Sensor](img/IMG_2563-450px.jpg)

### Notes
* WiringPi is a well documented, nicely designed, easy to use library but it has been deprecated; future prototypes will not include this library
* WiringPi includes a tool called "gpio", which is helpful for troubleshooting (basic usage included below)

### Usage
~~~
sudo ./gpio-asm

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
$GPVTG,123.45,T,,M,0.78,N,0.91,K,D*2C
$GPGGA,345670.000,8976.1234,N,01234.5678,W,2,10,1.23,456.7,M,-89.7,M,0000,0000*89
$GPGSA,A,1,23,45,67,89,01,,,,,,,,1.23,4.56,7.89*09
$GPRMC,9876543.000,A,4567.8901,N,012345.8765,W,0.12,345.67,123456,,,D*88
$GPVTG,123.45,T,,M,0.78,N,0.91,K,D*2C

---[ Disable GPS Sensor ]---
 > Disabling TxD... disabled!
 > Disabling RxD... disabled!

---[ Exit ]---
~~~
