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

.PHONY: all clean

clean:
	rm -f ${LDIR}*.a ${ODIR}HT16K33.o
