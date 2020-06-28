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
    char setupCommands[3] = {0x21,0xef,0x81};
	if (write(file, setupCommands, 3) != 3){
        perror("Failed to setup display\n");
        return 1;
    }

	usleep(50);

    printf("Setup complete. Sending commands...\n");

	char registerPtr[1] = {0x00};
    write(file, registerPtr, 1);

    char setLED[1] = {0xff};
    // Set all LEDs on
    for (int i=0; i < 10; i++){
        write(file, setLED, 1);
    }

	close(file);
	
	return 0;
}
