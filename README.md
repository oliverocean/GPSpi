# GPSpi
**A simple, end-to-end, GPS location tracking system:**</br>
Gathers GPS data from a physical sensor and displays location information on a mobile app dashboard.

### Software
* Written in C and assembly language
* Uses the [ARMv8](https://developer.arm.com/documentation/den0024/a/an-introduction-to-the-armv8-instruction-sets) instruction set architecture
* Assembly language instructions embedded into C code using [asm](https://gcc.gnu.org/onlinedocs/gcc/Using-Assembly-Language-with-C.html), a C language extension
* UART serial communication enabled using [libgpiod](https://git.kernel.org/pub/scm/libs/libgpiod/libgpiod.git/about/) (GPIO character device interface)
* GPS data stream parsed with [gpsd](https://gpsd.gitlab.io/gpsd/index.html)

### Configuration
* Host machine: [Raspberry Pi 3](https://www.raspberrypi.org/documentation/hardware/raspberrypi/README.md) (model B+)
* Operating system: Arch Linux ARM, an [AArch64](https://archlinuxarm.org/packages/aarch64/linux-aarch64) package (64-bit OS needed for ARMv8 ISA)
* GPS sensor: [MTK3339](https://learn.adafruit.com/adafruit-ultimate-gps/overview) (Adafruit) with external GPS antenna
* User dashboard: [Blynk.io](https://docs.blynk.cc/) app

![MT3339 GPS Sensor](img/IMG_2563-450px.jpg)

### Notes
Development currently in progress!</br>
Completion of MVP prototype expected 31-Jul.
