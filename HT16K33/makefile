# IDIR = ../include
CC=cc
#CFLAGS=-I$(IDIR)

ODIR=../obj

TARGET=userDisplay

_DEPS = HT16K33.h
#DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = $(TARGET).o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# all will use first command unless otherwise told
all: clean $(TARGET)

$(ODIR)/%.o: %.c $(_DEPS)
	$(CC) -c -o $@ $<

# make knows the OBJ must be created first when they are a dependent.
$(TARGET): $(OBJ)
	$(CC) -o $@ $^
    
.PHONY: all clean

clean:
	rm -f $(ODIR)/*.o *~ $(TARGET)
