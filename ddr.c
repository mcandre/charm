#include "charm.h"
#include <gc.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void draw_score(int score) {
	move_cursor(1, 3);
	char *m = (char *) GC_MALLOC(20 * sizeof(char));
	sprintf(m, "SCORE %04d", score);
	hcenter_string(m);
}

void draw_arrow(key arrow) {
	move_cursor(1, 5);

	switch(arrow) {
		case KEY_UP:
			hcenter_string("^");
			break;
		case KEY_DOWN:
			hcenter_string("v");
			break;
		case KEY_RIGHT:
			hcenter_string(">");
			break;
		case KEY_LEFT:
			hcenter_string("<");
			break;
		default:;
	}
}

void draw_hoot(int hoot) {
	move_cursor(1, 7);

	if (hoot == 0) {
		hcenter_string("GOOD!");
	}
	else {
		hcenter_string("BAD! ");
	}
}

int main() {
	srand(time(NULL));

	GC_INIT();

	start_charm();

	hcenter_string("DDR: How fast can you play?");

	int score = 0;
	int delta = 0;

	key arrow = KEY_UP + (rand() % 4);

	key k = KEY_UNKNOWN;

	while(k != KEY_ESCAPE && k != KEY_Q) {
		draw_score(score);

		draw_arrow(arrow);

		k = get_key();

		delta = (arrow - k);

		if (delta == 0) {
			score++;
		}
		else {
			score--;
		}

		draw_hoot(delta);

		arrow = KEY_UP + (rand() % 4);
	}

	end_charm();

	return 0;
}