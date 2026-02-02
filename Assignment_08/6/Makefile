CC = gcc
PIC = -fPIC
SS = -shared

app: main.c so
	$(CC) main.c -o  app

so: 
	$(CC) $(PIC) $(SS) -o libmath.so math.c

run: app
	LD_LIBRARY_PATH=. ./app 

clean:
	rm -f *.so app

