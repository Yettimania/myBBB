IDIR = ../include
CC=cc
CFLAGS=-I$(IDIR)

ODIR=obj

TARGET=userDisplay

_DEPS = HT16K33.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = $(TARGET).o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: clean $(TARGET)

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CLAGS) 
    
.PHONY: all clean

clean:
	rm -f $(ODIR)/*.o *~ $(TARGET)
