CC = gcc

app: main.o helper.o
	$(CC) main.o helper.o -o app

main.o: main.c helper.h
	$(CC) -c main.c

helper.o: helper.c helper.h
	$(CC) -c helper.c 

run: 
	./app

clean:
	rm -f *.o app

.PHONY: run clean