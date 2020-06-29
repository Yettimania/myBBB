#include<stdio.h>
#include<fcntl.h>
#include<sys/ioctl.h>
#include<linux/i2c.h>
#include<linux/i2c-dev.h>
#include<unistd.h>

#include "HT16K33.h"

static char digits[10] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0xfd, 0x07, 0x7f, 0x67 };
static char usedReg[4] = { 0x00, 0x02, 0x06, 0x08 };

int
initialize(int file)
{
    char setOsc[1] = {0x21};
    char setBrightness[1] = {0xef};
    char blinkOff[1] = {0x81};


   	if (write(file, setOsc, 1) != 1){
        perror("Failed to start oscillator\n");
        return 1;
    }
	if (write(file, setBrightness, 1) != 1){
        perror("Failed to set brightness\n");
        return 1;
    }
	if (write(file, blinkOff, 1) != 1){
        perror("Failed to write blink register\n");
        return 1;
    }

    usleep(50000);

    printf("Initialization complete.\n");
}

int main() {
	int file;

	printf("Starting the HT16K33 test application...\n");

	if ((file=open("/dev/i2c-2", O_RDWR)) < 0){
	  perror("failed to open the bus\n");
	  return 1;
	}

	if (ioctl(file, I2C_SLAVE, 0x70) < 0){
		perror("Failed to connect to the sensor\n");
		return 1;
	}

    // Setup prior to sending data
    initialize(file);

    // Display user input
    char display[] = "2094";
    char buffer[2] = { };
    
    //Find correct register and store in buffer
    //Find correct digit display to write to register
    //Update display left to right.
    int x;
    for (int i=0;i<4;i++) {
        buffer[0] = usedReg[i];
        x = display[i] - '0'; //Corrects variable for ascii value based on '0'
        buffer[1] = digits[x];
        write(file,buffer,2);
    }

    printf("Displaying user input...\n");

    usleep(5000000);

    printf("Turning all LEDs on ...\n");

	char onCommand[17] = {0x00,0xff,0xff,0xff,0xff\
                              ,0xff,0xff,0xff,0xff\
                              ,0xff,0xff,0xff,0xff\
                              ,0xff,0xff,0xff,0xff};

    write(file,onCommand,17);

    usleep(2000000);

    printf("Turning all LEDs off...\n");

	char offCommand[17] = {0x00,0x00,0x00,0x00,0x00\
                               ,0x00,0x00,0x00,0x00\
                               ,0x00,0x00,0x00,0x00\
                               ,0x00,0x00,0x00,0x00};

    write(file,offCommand,17);

	close(file);
	
	return 0;
}
