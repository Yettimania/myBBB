CC=cc

IDIR = ./include/
SDIR = ./src/
LDIR = ./lib/
ODIR = ./obj/
CFLAGS=-I${IDIR}

all: libHT16K33.a

libHT16K33.a: ${SDIR}HT16K33.c ${IDIR}HT16K33.h HT16K33.o
	ar -rs ${LDIR}libHT16K33.a ${ODIR}HT16K33.o

HT16K33.o: ${IDIR}HT16K33.h ${SDIR}HT16K33.c
	$(CC) -c ${SDIR}HT16K33.c -o ${ODIR}HT16K33.o ${CFLAGS}

gpioLED: gpioLED.o
	$(CC) -o ./gpioLED/gpioLED ${ODIR}gpioLED.o

gpioLED.o: ./gpioLED/gpioLED.c
	$(CC) -c ./gpioLED/gpioLED.c -o ${ODIR}gpioLED.o

test: ./gpioLED/gpioLED.c
	$(CC) -c ./gpioLED/gpioLED.c -o ${ODIR}gpioLED.o
	$(CC) -o ./gpioLED/gpioLED ${ODIR}gpioLED.o

.PHONY: all clean

clean:
	rm -f ${LDIR}*.a ${ODIR}HT16K33.o
