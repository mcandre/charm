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

splint:
	find . -type f -name '*.[ch]' -exec splint {} \;

vera++:
	find . -type f -name '*.cpp' -o -name '*.[ch]' -exec vera++ -s {} \;

lili:
	bundle exec lili .

editorconfig:
	find . -type f -name Thumbs.db -prune -o -type f -name .DS_Store -prune -o -type d -name .git -prune -o -type d -name .svn -prune -o -type d -name tmp -prune -o -type d -name bin -prune -o -type d -name target -prune -o -name "*.app*" -prune -o -type d -name node_modules -prune -o -type d -name bower_components -prune -o -type f -name "*[-.]min.js" -prune -o -type d -name "*.dSYM" -prune -o -type f -name "*.scpt" -prune -o -type d -name "*.xcodeproj" -prune -o -type d -name .vagrant -prune -o -type f -name .exe -prune -o -type f -name "*.o" -prune -o -type f -name "*.pyc" -prune -o -type f -name "*.hi" -prune -o -type f -name "*.beam" -prune -o -type f -name "*.png" -prune -o -type f -name "*.gif" -prune -o -type f -name "*.jp*g" -prune -o -type f -name "*.ico" -prune -o -type f -name "*.ttf" -prune -o -type f -name "*.zip" -prune -o -type f -name "*.jar" -prune -o -type f -name "*.dot" -prune -o -type f -name "*.pdf" -prune -o -type f -name "*.wav" -prune -o -type f -name "*.mp[34]" -prune -o -type f -name "*.svg" -prune -o -type f -name "*.flip" -prune -o -type f -name "*.class" -prune -o -type f -name "*.jad" -prune -o -type d -name .idea -prune -o -type f -name "*.iml" -prune -o -type f -name "*.log" -prune -o -type f -name "*" -exec node_modules/editorconfig-tools/bin/index.js check {} \;

lint: splint vera++ lili editorconfig

valgrind: $(BIN)
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --track-fds=yes --dsymutil=yes echo q | ./hellocharm

churn:
	bundle exec churn

clean:
	-rm *.exe
	-rm *.o
	-rm rl
	-rm ddr
	-rm hellocharm
