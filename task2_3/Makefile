CC = gcc
LDFLAGS = -lm
TARGET = Task2_3

all: $(TARGET)

$(TARGET): Task2_3.c
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TARGET)

.PHONY: all clean
