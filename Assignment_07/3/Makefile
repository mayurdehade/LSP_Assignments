
client:
	gcc client.c -o client -ldl

libdisplay:
	gcc -fPIC -shared -o libdisplay.so display.c

run:
	./client

clean:
	rm -f *.so client