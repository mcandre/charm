#include "charm.h"
#include <gc.h>
#include <stdio.h>

int main() {
	start_charm();

	key k = KEY_UNKNOWN;
	char *m;

	while(k != KEY_Q) {
		k = get_key();
		m = (char *) GC_MALLOC(10 * sizeof(char));
		sprintf(m, "Key: %d", k);
		center_string(m);
	}

	end_charm();

	return 0;
}