CC = gcc
LDFLAGS = -lm
TARGET = Task2_2

all: $(TARGET)

$(TARGET): Task2_2.c
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TARGET)

.PHONY: all clean
