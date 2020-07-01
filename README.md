# Beaglebone Black Development

Series of programs written in C for use with the BeagleBone Black. Started with a number of devices I had sitting around.

We love the BeagleBoneBlack and Linux.

## makeLED - Onboard LED

Simple C program that flashes the onboard user LED.

## gpioLED - Basic Example

Connected to a single GPIO pin. It simply blinks the light a few times. Nothing too exciting. Basic principles of GPIO.

## TSL2561 - Light Sensor over I2C

This is the Adafruit breakout board light sensor. It communicates over I2C and has two sensors on board. One more sensitive to visible light and the other sensitive to infrared light. This C program will read the 2 bytes sent from each sensor. The data sheet has a calculation that is used to then calculate the lux value. That has not been implemented in this program but can easily be done.

## HT16K33 - 7 Segment Display I2C

This is the Adafruit 7 segment display using the HT16K33 chip. There is a simple test program within this folder that will initialize the display, turn all segments on and all segments off. The *userDisplay* script is a C program that will display a character defined array. This can easily be used or modified to display sensor data, user input, etc.  
