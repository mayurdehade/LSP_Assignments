
client:
	gcc client.c -o client -ldl

libmystring:
	gcc -fPIC -shared -o libmystring.so mystring.c

run:
	./client

clean:
	rm -f *.so client