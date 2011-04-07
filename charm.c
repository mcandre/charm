#include "charm.h"
#include <locale.h>
#include <stdio.h>

// ANSI Escape Codes
// http://en.wikipedia.org/wiki/ANSI_escape_code

void hide_cursor() {
	printf("\033[?25l");
}

void show_cursor() {
	printf("\033[?25h");
}

void move_cursor(int x, int y) {
	printf("\033[%d;%dH", y, x);
}

void clear_screen() {
	printf("\033[2J");
}

void start_charm() {
	hide_cursor();
	move_cursor(0, 0);
	clear_screen();
}

void end_charm() {
	clear_screen();
	show_cursor();

	// ...
}

// ...