#include "charm.h"
#include <stdio.h>
#include <string.h>

int main() {
	start_charm();

	vcenter_string("Hello Charm! Press Escape-Escape, q, or Control-C to quit.");

	key k = KEY_UNKNOWN;

	while(k != KEY_ESCAPE && k != KEY_Q) {
		k = get_key();
	}

	end_charm();

	return 0;
}