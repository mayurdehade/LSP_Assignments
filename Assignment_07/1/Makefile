client: libperfect
	gcc -o client client.c -L. -lperfect -lhelper

libperfect: libhelper
	gcc -fPIC -shared -o libperfect.so perfect.c

libhelper:
	gcc -fPIC -shared -o libhelper.so helper.c 

run:
	./client

clean:
	rm -f *.so *.o client