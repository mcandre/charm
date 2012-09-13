LGC=-lgc

all: hellocharm

charm.o: charm.c charm.h
	gcc -c charm.c charm.h

hellocharm: hellocharm.c charm.c charm.h
	gcc -o hellocharm hellocharm.c charm.c charm.h -Wall

ddr: ddr.c charm.c charm.h
	gcc -o ddr ddr.c charm.c charm.h -Wall $(LGC)

rl: rl.c charm.c charm.h
	gcc -o rl rl.c charm.c charm.h -Wall $(LGC)

install: charm.c charm.h
	cp charm.h /usr/include
	sed s/'#include "charm.h"'/'#include <charm.h>'/ charm.c > /usr/include/charm.c

uninstall:
	-rm /usr/include/charm.c
	-rm /usr/include/charm.h

clean:
	-rm rl
	-rm ddr
	-rm hellocharm
	-rm *.o