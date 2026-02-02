CC = gcc

app: main.c libmath.a 
	$(CC) main.c libmath.a -o app

libmath.a: math.o
	ar rcs libmath.a math.o

math.o: 
	$(CC) -c math.c

run:
	./app


clean:
	rm -f *.a *.o app


