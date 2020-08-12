### GPSpi Prototype B
Gathers GPS data from a physical sensor and displays location information on a mobile app dashboard.

### Software
* Written in TBD - researching this currently (need to ensure compatibility with dashboard platform)
* (perhaps) UART serial communication enabled using [libgpiod](https://git.kernel.org/pub/scm/libs/libgpiod/libgpiod.git/about/) (GPIO character device interface)

### Configuration
* Host machine: [Raspberry Pi 3](https://www.raspberrypi.org/documentation/hardware/raspberrypi/README.md) (model B+)
* Operating system: Arch Linux ARM, an [AArch64](https://archlinuxarm.org/packages/aarch64/linux-aarch64) package (64-bit OS needed for ARMv8 ISA)
* GPS sensor: [MTK3339](https://learn.adafruit.com/adafruit-ultimate-gps/overview) (Adafruit) with external GPS antenna
* User dashboard: [Blynk.io](https://docs.blynk.cc/) app

(Development currently in progress, updates soon)
