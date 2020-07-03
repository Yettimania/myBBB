/* These are the functions associated with the HT16K33 chip to control the 7 segment display over i2c. These functions are based on the datasheet and are the primary functions to use the device.
Author: Kyle Snyder
Date: July 03, 2020
*/

/* These are the used registers for the 7 segment display
that need to be accessed to write the valid characters.*/

#include "HT16K33.h"

static char usedReg[4] = { 0x00, 0x02, 0x06, 0x08 );

static int
startOscillation(void){

   char cmd[1] = {0x21};

   if (write(file, cmd, 1) != 1){
       perror("failed to start oscillator\n");
       return 1;
   }
}

int
setBrightness(int x){

   char cmd[1] = {0xef};

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
blink(int x){
   char cmd[1] = {0x81};
   if (write(file, cmd, 1) != 1){
       perror("Failed to write blink register\n");
       return 1;
   }
}
