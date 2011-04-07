#include "charm.h"
#include "key.h"
#include <gc.h>
#include <stdio.h>
#include <string.h>

int main() {
	start_charm();

	center_string("Hello Charm! Press \'q\' to quit.");

	key k = KEY_UNKNOWN;

	while(k != KEY_Q) {
		k = get_key();
	}

	end_charm();

	return 0;
}