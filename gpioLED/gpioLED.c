#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define GPIO_PATH "/sys/class/gpio/gpio68"

// function prototypes
void writeLED(char filename[], char value[]);

int main (){
	writeLED("/direction", "out"); // set direction for pin
    printf("Beginning to blink LED 10 times.\n");
    for (int i=0;i<10;i++){
        writeLED("/value", "1");
        sleep(1);
        writeLED("/value", "0");
        sleep(1);
		printf("Blink %d\n", i);
    }
    printf("Blinking complete.\n");
	
    return 0;
}

void writeLED(char filename[],char value[]){
    FILE* fp; //create file pointer
    char fullFileName[100]; //store path and filename
    sprintf(fullFileName, GPIO_PATH "%s", filename); // write path/name
    fp = fopen(fullFileName, "w+"); //open file for writing
    fprintf(fp, "%s", value); // send value to the file
    fclose(fp); // close the file using the file pointer
}
