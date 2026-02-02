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

help:
	@echo "Usage: "
	@echo "make 		--> build the program"
	@echo "make run 	--> run the program"
	@echo "make clean 	--> remove build files"