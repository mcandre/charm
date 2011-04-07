EXECUTABLE=hellocharm

all: hellocharm.c charm.c charm.h
	gcc -o $(EXECUTABLE) hellocharm.c charm.c charm.h -Wall -lgc

clean:
	-rm $(EXECUTABLE)