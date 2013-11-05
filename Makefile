CC=clang
FLAGS=-Wall -Wextra -Wmost -Weverything -Wno-switch-enum

all: hellocharm ddr rl

charm.o: charm.c charm.h
	$(CC) -c charm.c charm.h

hellocharm: hellocharm.c charm.c charm.h
	$(CC) $(FLAGS) -o hellocharm hellocharm.c charm.c

ddr: ddr.c charm.c charm.h
	$(CC) $(FLAGS) -o ddr ddr.c charm.c -lgc

rl: rl.c charm.c charm.h
	$(CC) $(FLAGS) -o rl rl.c charm.c -lgc

install: charm.c charm.h
	cp charm.h /usr/include
	sed s/'#include "charm.h"'/'#include <charm.h>'/ charm.c > /usr/include/charm.c

uninstall:
	-rm /usr/include/charm.c
	-rm /usr/include/charm.h

lint:
	splint *.c *.h -preproc

clean:
	-rm *.exe
	-rm *.o
	-rm rl
	-rm ddr
	-rm hellocharm
