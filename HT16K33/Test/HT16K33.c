#include<stdio.h>
#include<fcntl.h>
#include<sys/ioctl.h>
#include<linux/i2c.h>
#include<linux/i2c-dev.h>
#include<unistd.h>

#define BUFFER_SIZE 10

int main(){
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
    // setOscillator, setBrightness, Blinkoff
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

    printf("Setup complete.\n");

    // Now we can begin sending commands
    printf("Turning all LEDs on...\n");

	char onCommand[17] = {0x00,0xff,0xff,0xff,0xff\
                               ,0xff,0xff,0xff,0xff\
                               ,0xff,0xff,0xff,0xff\
                               ,0xff,0xff,0xff,0xff};

    write(file,onCommand,17);

    usleep(5000000);

    printf("Turning all LEDs off...\n");

	char offCommand[17] = {0x00,0x00,0x00,0x00,0x00\
                               ,0x00,0x00,0x00,0x00\
                               ,0x00,0x00,0x00,0x00\
                               ,0x00,0x00,0x00,0x00};

    write(file,offCommand,17);

	close(file);
	
	return 0;
}
