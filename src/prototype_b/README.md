### GPSpi
Prototype B: summary

### Software
* Written in C and assembly language
* Uses the [ARMv8](https://developer.arm.com/documentation/den0024/a/an-introduction-to-the-armv8-instruction-sets) instruction set architecture
* Assembly language instructions embedded into C code using [asm](https://gcc.gnu.org/onlinedocs/gcc/Using-Assembly-Language-with-C.html), a C language extension
* UART serial communication enabled using the [wiringPi](http://wiringpi.com/) library

### Configuration
* Host machine: [Raspberry Pi 3](https://www.raspberrypi.org/documentation/hardware/raspberrypi/README.md) (model B+)
* Operating system: Ubuntu Server 18.04 (64-bit) for Raspberry Pi, an [AArch64](https://archlinuxarm.org/packages/aarch64/linux-aarch64) package (64-bit OS needed for ARMv8 ISA)
* GPS sensor: [MTK3339](https://learn.adafruit.com/adafruit-ultimate-gps/overview) (Adafruit) with external GPS antenna

![MT3339 GPS Sensor](../../img/IMG_2563-450px.jpg)

### Notes
* WiringPi is a well documented, nicely designed, easy to use library but it has been deprecated; future prototypes will not include this library
* After extensive testing, WiringPi does not appear to work with Arch Linux, thus this prototype uses Ubuntu Linux
* WiringPi includes a tool called "gpio", which is helpful for troubleshooting (basic usage included below)

### Usage
~~~
usage here
~~~
