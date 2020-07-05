# Beaglebone Black Development

Series of programs written in C for use with the BeagleBone Black. Started with a number of devices I had sitting around.

We love the BeagleBoneBlack and Linux!!

## Organization and Folder Structure

Below is the folder structure of the BBB. All files are simply in the home directory; including unique libraries and header files that I've developed.

`include` contains all the header files that are created and used for BBB

`src`these are all the .c files that I've created, used on the BBB

`makefile` The makefile has a number of utilizations. It's primary use is to generate libraries that have been created for specific devices I have. The makefile will look for a `lib` and `obj` folder. These folders should be create at the same level as the other folders.

When using the makefile, it will store .o files in `obj` and compile the static libraries into the `lib` folder.

## Libraries
1. **HT16K33** - Used to contorl an external 7 segment display over i2c.

## Programs

### makeLED - Onboard LED

Simple C program that flashes the onboard user LED.

### gpioLED - Basic Example

Connected to a single GPIO pin. It simply blinks the light a few times. Nothing too exciting. Basic principles of GPIO.

### TSL2561 - Light Sensor over I2C

This is the Adafruit breakout board light sensor. It communicates over I2C and has two sensors on board. One more sensitive to visible light and the other sensitive to infrared light. This C program will read the 2 bytes sent from each sensor. The data sheet has a calculation that is used to then calculate the lux value. That has not been implemented in this program but can easily be done.
