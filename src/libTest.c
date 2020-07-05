#include<stdio.h>
#include<fcntl.h>
#include<sys/ioctl.h>
#include<linux/i2c.h>
#include<linux/i2c-dev.h>
#include<unistd.h>
#include<HT16K33.h>

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
    startOscillation(file);
    setBrightness(file,15);
    blink(file,1);

    setDisplay(file,"12.34");
    usleep(5000000);
    setDisplay(file,"-876");

    printf("Displaying user input...\n");

	close(file);
	
	return 0;
}
