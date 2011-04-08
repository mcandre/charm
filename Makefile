CFLAGS=-arch i386 -arch x86_64
LGC=-L/opt/local/lib -lgc

all: hellocharm

charm.o: charm.c charm.h
	gcc -c charm.c charm.h

libcharm.dylib: charm.o
	gcc $(CFLAGS) -dynamiclib -o libcharm.dylib -flat_namespace charm.o $(LGC)

hellocharm: hellocharm.c libcharm.dylib
	gcc -o hellocharm hellocharm.c -Wall $(LGC) -L. -lcharm

ddr: ddr.c libcharm.dylib
	gcc -o ddr ddr.c -Wall $(LGC) -L. -lcharm

install: libcharm.dylib
	cp libcharm.dylib /usr/lib/

uninstall:
	-rm /usr/lib/libcharm.dylib

clean:
	-rm ddr
	-rm hellocharm
	-rm *.dylib
	-rm *.o
	-rm *.gch