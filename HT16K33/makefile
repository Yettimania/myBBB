IDIR=../include
CC=cc
CFLAGS=-I$(IDIR)

ODIR=../obj

_DEPS = HT16K33.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = libTest.o HT16K33.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# all will use first command unless otherwise told
all: clean libTest

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# make knows the OBJ must be created first when they are a dependent.
libTest: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
    
.PHONY: all clean

clean:
	rm -f $(ODIR)/*.o *~ $(TARGET)
