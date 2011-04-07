#include "charm.h"
#include <gc.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ANSI Escape Codes
// http://en.wikipedia.org/wiki/ANSI_escape_code

// Terminal information
// http://developer.apple.com/library/mac/#documentation/Darwin/Reference/ManPages/man4/tty.4.html

// Disabling echo
// http://www.gnu.org/s/hello/manual/libc/getpass.html

int pos_x;
int pos_y;

int get_width() {
	struct winsize ws;
	ioctl(0, TIOCGWINSZ, &ws);

	return ws.ws_col;
}

int get_height() {
	struct winsize ws;
	ioctl(0, TIOCGWINSZ, &ws);

	return ws.ws_row;
}

void cursor_off() {
	printf("\033[?25l");
}

void cursor_on() {
	printf("\033[?25h");
}

void echo_off() {
	struct termios term;
	tcgetattr(fileno(stdout), &term);
	term.c_lflag &= ~ECHO;
	tcsetattr(fileno(stdout), TCSAFLUSH, &term);
}

void echo_on() {
	struct termios term;
	tcgetattr(fileno(stdout), &term);
	term.c_lflag |= ECHO;
	tcsetattr(fileno(stdout), TCSAFLUSH, &term);
}

void raw_on() {
	struct termios term;
	tcgetattr(fileno(stdout), &term);
	term.c_lflag &= ~ICANON;
	tcsetattr(fileno(stdout), TCSAFLUSH, &term);
}

void raw_off() {
	struct termios term;
	tcgetattr(fileno(stdout), &term);
	term.c_lflag |= ICANON;
	tcsetattr(fileno(stdout), TCSAFLUSH, &term);
}

void move_cursor(int x, int y) {
	pos_x = x;
	pos_y = y;
	printf("\033[%d;%dH", y, x);
}

void put_char(char c) {
	if (c == '\n') {
		move_cursor(0, pos_y + 1);
	}
	else {
		putchar(c);
		fflush(stdout);
		pos_x++;
	}
}

void put_string(char *s) {
	int i;
	for (i = 0; i < strlen(s); i++) {
		put_char(s[i]);
	}
}

void center_string(char *s) {
	move_cursor((get_width() - strlen(s))/2, get_height()/2);
	put_string(s);
}

void clear_screen() {
	printf("\033[2J");
}

void handle_signal(int signal) {
	end_charm();
	exit(0);
}

void start_charm() {
	GC_INIT();

	signal(SIGINT, handle_signal);

	cursor_off();
	echo_off();
	raw_on();
	move_cursor(0, 0);
	clear_screen();
}

void end_charm() {
	move_cursor(0, 0);
	clear_screen();
	cursor_on();
	echo_on();
	raw_off();
}