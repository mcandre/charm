#include "charm.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
	start_charm();

	int message_space = 3;

	int x = 1, y = 1;

	clear_screen();
	move_cursor(x, y);
	blot_char('@');

	key k = get_key();

	while (k != KEY_ESCAPE && k != KEY_Q) {
		switch (k) {
			case KEY_UP: if (y > 1) { y--; } break;
			case KEY_DOWN: if (y < get_height() - message_space) { y++; } break;
			case KEY_RIGHT: if (x < get_width()) { x++; } break;
			case KEY_LEFT: if (x > 1) { x--; } break;
			default:;
		}

		clear_screen();

		char *message = (char *) malloc(20 * sizeof(char));
		sprintf(message, "Cursor: (%d, %d)", get_x(), get_y());
		move_cursor(0, get_height());
		hcenter_string(message);

		move_cursor(x, y);
		blot_char('@');

		k = get_key();
	}

	end_charm();

	return 0;
}