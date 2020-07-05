# Embedded Beaglebone in C

Series of programs written in C for use with the BeagleBone Black. Started with a number of devices I had sitting around. The device libraries should be applicable to any embedded linux i2c communication as they work on the i2c bus and are not pin specific. Any program that utilizes unique pins on a device would need to be updated to your specific device.

## Organization and Folder Structure

Below is the folder structure of the BBB. All files are in the `home` directory; including unique libraries and header files that I've developed.

`include` contains all the header files that are created and used for BBB. This includes specific device libraries.

`src`these are all the .c files that I've created, used on the BBB. Once the repository is cloned, this need to be compiled for the specific hardware. 

`makefile` The makefile has a number of utilizations. It's primary use is to generate libraries that have been created for specific devices I have. The makefile will look for a `lib` and `obj` folder. These folders should be create at the same level as the other folders.

When using the makefile, it will store .o files in `obj` and compile the static libraries into the `lib` folder. These libraries to communicate to specific i2c devices can then be used in other programs.

## Libraries

### HT16K33

This is the chip used on the Adafruit 7 segment display. This library has been uniquely created for that device with specific register mapping. The functions in the library are contained within the HT16K33 header file.

1. startOscillation(int file) - Will turn the chips oscillator on, powering the device. The `file` is the pointer used to communicate to specifc device.
2. setBrightness(int file, int value) - Set the display brightness with a value from 0 to 15. 
3. blink(int file, int value) - WIP...
4. setDisplay(int file, char[4]) - Set the 4 characters to display on the device. This will write to the appropriate registers for the Adafruit i2c backpack.WIP 

## Programs

### makeLED - Onboard LED

Simple C program that flashes the onboard user LED. 

### gpioLED - Basic Example

Connected to a single GPIO pin. It simply blinks the light a few times. Basic principles of GPIO.

### TSL2561 - Light Sensor over I2C

This is the Adafruit breakout board light sensor. It communicates over I2C and has two sensors on board. One more sensitive to visible light and the other sensitive to infrared light. This C program will read the 2 bytes sent from each sensor. The data sheet has a calculation that is used to then calculate the lux value. That has not been implemented in this program but can easily be done.
