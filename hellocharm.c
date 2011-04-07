#include "charm.h"
#include <gc.h>
#include <stdio.h>

int main() {
	start_charm();

	printf("Getting width...\n");

	int w = get_width();

	printf("width = %d\n", w);

	printf("Getting height...\n");

	int h = get_height();

	printf("height = %d\n", h);

	printf("constructing message...\n");

	char *message = (char *) GC_MALLOC(30 * sizeof(char));

	printf("zeroing message...\n");

	int i;
	for (i = 0; i < 30; i++) { message[i] = '\0'; }

	sprintf(message, "Width: %d Height: %d", w, h);

	printf("message = %s\n", message);

	add_string(message);

	// ...

	end_charm();

	return 0;
}