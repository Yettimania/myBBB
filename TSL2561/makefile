CC=cc
TARGET=TSL2561

all: clean $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) -o $(TARGET) $(TARGET).c
    
.PHONY: all clean

clean:
	rm -f $(TARGET)
