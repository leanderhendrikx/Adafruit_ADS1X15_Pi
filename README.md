# Adafruit_ADS1015_Pi 
Raspberry Pi/C++ library for the Adafruit ADS1X15 using smbus.

Changes:
- The Adafruit_I2CDevice dependency is replaced by smbus.
- Arduino & Wire dependencies are removed.
- Examples are ported to C++.
- `continuous` example is removed because it would require a C/C++ gpio
  interrupt library to function correctly. However, the library is fully functional
  and the ALRT pin can be used for interrupts.

## Instructions
The library and examples can be built using cmake >3.10:

```
mkdir build && cd build
cmake ..
cmake --build . --target all
```

The only dependency is `libi2c-dev` for i2c communication with the ADC.
```apt install libi2c-dev```

I2C needs to be enabled on the Pi and can be done using `raspi-config`.
```raspi-config -> interface options -> enable i2c```

------------------Original README.md------------------
# Adafruit_ADS1015 


Driver for TI's ADS1X15: 12 and 16-bit Differential or Single-Ended ADC with PGA and Comparator

## Info

This family of ADCs provide 4 single-ended or 2 differential channels.
Each has a programmable gain amplifier from 2/3 up to 16x. Available
in 12 or 16 bit versions:

* [ADS1015 12-bit ADC](https://www.adafruit.com/product/1083)
* [ADS1115 16-bit ADC](https://www.adafruit.com/product/1085)

The chip's fairly small so it comes on a breakout board with ferrites to keep the AVDD and AGND quiet. Interfacing is done via I2C. The address can be changed to one of four options (see the datasheet table 5) so you can have up to 4 ADS1x15's connected on a single 2-wire I2C bus for 16 single ended inputs.

Adafruit invests time and resources providing this open source code, please
support Adafruit and open-source hardware by purchasing products from
[Adafruit](https://www.adafruit.com)!

## License

 BSD license, all text above must be included in any redistribution.
