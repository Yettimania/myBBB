#include<stdio.h>
#include<fcntl.h>
#include<sys/ioctl.h>
#include<linux/i2c.h>
#include<linux/i2c-dev.h>
#include<unistd.h>

#define BUFFER_SIZE 2

int main(){
	int file;

	printf("Starting the TSL2561 test application...\n");

	if ((file=open("/dev/i2c-2", O_RDWR)) < 0){
	  perror("failed to open the bus\n");
	  return 1;
	}
	printf("Bus opened...\n");
	if (ioctl(file, I2C_SLAVE, 0x39) < 0){
		perror("Failed to connect to the sensor\n");
		return 1;
	}
	printf("Powering device...\n");
	char commandStart[2] = {0xa0,0x03};
	write(file, commandStart, 2);
	
	usleep(500);

	printf("Connected to sensor...\n");
	char writeBuffer[1] = {0xac};
	if (write(file, writeBuffer, 1) !=1){
		perror("Failed to execute command\n");
		return 1;
	}
	printf("Read command sent...\n");
	char buf[BUFFER_SIZE];

	if (read(file, buf, BUFFER_SIZE) != BUFFER_SIZE){
		perror("Failed to read in the buffer\n");
		return 1;
	}

	printf("Channel 0 Low: %x\n",buf[0]);
	printf("Channel 0 High: %x\n",buf[1]);
	

	char writeBuffer2[1] = {0xae};
	if (write(file,writeBuffer2, 1) !=1){
		perror("Failed to execute command\n");
		return 1;
	}
	if (read(file, buf, BUFFER_SIZE) != BUFFER_SIZE){
		perror("Failed to read in the buffer\n");
		return 1;
	}

	close(file);

	printf("Channel 1 Low: %x\n",buf[0]);
	printf("Channel 2 High: %x\n",buf[1]);
	
	return 0;
}
