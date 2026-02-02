library:
	gcc -fPIC -shared -o libaddition.so addition.c
	gcc -fPIC -shared -o libsubstraction.so substraction.c

client:
	gcc client.c -o client -ldl

clean:
	rm -f *.so client

run:
	./client