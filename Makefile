all: hellocharm.c charm.c charm.h
	gcc -o hellocharm hellocharm.c charm.c charm.h -Wall -lgc

ddr: ddr.c charm.c charm.h
	gcc -o ddr ddr.c charm.c charm.h -Wall -lgc

clean:
	-rm hellocharm
	-rm ddr