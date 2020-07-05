CC=cc

IDIR = ./include/
SDIR = ./src/
LDIR = ./lib/
ODIR = ./obj/
CFLAGS=-I${IDIR}
LFLAGS=-L${LDIR}

# Used to build libraries specific to the beaglebone black
all: libHT16K33.a libTest

libHT16K33.a: ${SDIR}HT16K33.c ${IDIR}HT16K33.h HT16K33.o
	ar -rs ${LDIR}libHT16K33.a ${ODIR}HT16K33.o

HT16K33.o: ${IDIR}HT16K33.h ${SDIR}HT16K33.c
	$(CC) -c ${SDIR}HT16K33.c -o ${ODIR}HT16K33.o ${CFLAGS}

# make instructions for the various programs I've written for the beaglebone
# The .c files are stored in source, the .o files are stored in ./obj
# The program files are stored in home. 
gpioLED: ${SDIR}gpioLED.c
	$(CC) -c ${SDIR}gpioLED.c -o ${ODIR}gpioLED.o
	$(CC) -o gpioLED ${ODIR}gpioLED.o

TSL2561: ${SDIR}TSL2561.c
	$(CC) -c ${SDIR}TSL2561.c -o ${ODIR}TSL2561.o
	$(CC) -o TSL2561 ${ODIR}TSL2561.o

makeLED: ${SDIR}makeLED.c
	$(CC) -c ${SDIR}makeLED.c -o ${ODIR}makeLED.o
	$(CC) -o makeLED ${ODIR}makeLED.o

libTest: ${SDIR}libTest.c ${LDIR}libHT16K33.a
	$(CC) -c ${SDIR}libTest.c -o ${ODIR}libTest.o ${CFLAGS} ${LFLAGS} -lHT16K33
	$(CC) -o libTest ${ODIR}libTest.o ${CFLAGS} ${LFLAGS} -lHT16K33

.PHONY: all clean

clean:
	rm -f ${LDIR}*.a ${ODIR}HT16K33.o
