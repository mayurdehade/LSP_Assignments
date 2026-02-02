CC = gcc
CFLAGS = -Wall -Wextra -O2
SRC = main.c
TARGET = app


all: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm -f ./$(TARGET)