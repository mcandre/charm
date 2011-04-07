#include "charm.h"
#include <gc.h>
#include <stdio.h>
#include <string.h>

int main() {
	start_charm();

	char *message = "Hello Charm! Press Control+C to quit.";
	int message_len = strlen(message);

	move_cursor((get_width() - message_len)/2, get_height()/2);
	add_string("Hello Charm! Press Control+C to quit.");

	while(1) {}

	end_charm();

	return 0;
}