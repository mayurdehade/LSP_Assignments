client: libmymath libmystring
	gcc client.c -o client -ldl

libmymath:
	gcc -fPIC -shared -o libmymath.so mymath.c

libmystring:
	gcc -fPIC -shared -o libmystring.so mystring.c 

run:
	./client

clean:
	rm -f *.so client