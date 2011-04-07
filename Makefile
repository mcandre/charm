EXECUTABLE=hellocharm

all: hellocharm.c charm.c charm.h key.c key.h
	gcc -o $(EXECUTABLE) hellocharm.c charm.c charm.h key.c key.h -Wall -lgc

clean:
	-rm $(EXECUTABLE)