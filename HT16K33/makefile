CC=cc
TARGET=HT16K33

all: clean $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) -o $(TARGET) $(TARGET).c
    
.PHONY: all clean

clean:
	rm -f $(TARGET)
