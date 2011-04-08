CFLAGS=-arch i386 -arch x86_64
ICHARM=-I/usr/include
LGC=-L/opt/local/lib -lgc
LCHARM=-L. -lcharm

all: hellocharm

charm.o: charm.c charm.h
	gcc -c charm.c charm.h

libcharm.dylib: charm.o
	gcc $(CFLAGS) -dynamiclib -o libcharm.dylib -flat_namespace charm.o $(LGC)

hellocharm: hellocharm.c libcharm.dylib
	gcc -o hellocharm hellocharm.c -Wall $(ICHARM) $(LGC) $(LCHARM)

ddr: ddr.c libcharm.dylib
	gcc -o ddr ddr.c -Wall $(LGC) $(ICHARM) $(LCHARM)

install: charm.h libcharm.dylib
	cp charm.h /usr/include
	cp libcharm.dylib /usr/lib

uninstall:
	-rm /usr/lib/libcharm.dylib
	-rm /usr/include/charm.h

clean:
	-rm ddr
	-rm hellocharm
	-rm *.dylib
	-rm *.o
	-rm *.gch