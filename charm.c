#include "charm.h"
#include <gc.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ANSI Escape Codes
// http://en.wikipedia.org/wiki/ANSI_escape_code

// Terminal information
// http://developer.apple.com/library/mac/#documentation/Darwin/Reference/ManPages/man4/tty.4.html

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

void hide_cursor() {
	printf("\033[?25l");
}

void show_cursor() {
	printf("\033[?25h");
}

void move_cursor(int x, int y) {
	printf("\033[%d;%dH", y, x);
}

void put_char(char c) {
	putchar(c);
	fflush(stdout);
}

void put_string(char *s) {
	printf("%s", s);
	fflush(stdout);
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

	hide_cursor();
	move_cursor(0, 0);
	clear_screen();
}

void end_charm() {
	move_cursor(0, 0);
	clear_screen();
	show_cursor();

	// ...
}

// ...