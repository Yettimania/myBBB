/* These are the functions associated with the HT16K33 chip to control the 7 segment display over i2c. These functions are based on the datasheet and are the primary functions to use the device.
Author: Kyle Snyder
Date: July 03, 2020
*/

/* These are the used registers for the 7 segment display
that need to be accessed to write the valid characters.*/
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <unistd.h>
#include <HT16K33.h>

static char digits[10] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x67};
static char bright[16] = { 0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef };
static char usedReg[4] = { 0x00, 0x02, 0x06, 0x08 };

int
startOscillation(int file) {

   char cmd[1] = {0x21};

   if (write(file, cmd, 1) != 1){
       perror("failed to start oscillator\n");
       return 1;
   }
}

int
setBrightness(int file, int x) {

   char cmd[1] = { bright[x] };

   if (x<0 || x>15) {
       perror("brightness setting between 0 and 15\n");
       return 1;
   } else {
       if (write(file, cmd, 1) != 1) {
           perror("Failed to set brightness\n");
           return 1;
       }
   }
}

int
blink(int file, int x) {
   char cmd[1] = {0x81};
   if (write(file, cmd, 1) != 1){
       perror("Failed to write blink register\n");
       return 1;
   }
}

int
setDisplay(int file, char x[]) {
    int value;
    size_t LEN = strlen(x);
    char minus[1] = {0x40};
    char buffer[2] = { };

    printf("Display string is: %s\n",x);

    for (int i=0;i<4;i++) {
        buffer[0] = usedReg[i];
        
        if ( (int) x[i] == 45 ) {
            buffer[1] = minus[0];
        } else {
            value = x[i] - '0';
            buffer[1] = digits[value]; 
        }

        if (write(file,buffer,2) !=2) {
            perror("failed to write display register\n");
            return 1;
       }
    }
}


