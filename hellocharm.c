#include "charm.h"
#include <gc.h>
#include <stdio.h>

int main() {
	start_charm();

	add_string("Hello Charm! Press Control+C to quit.");

	while(1) {}

	end_charm();

	return 0;
}