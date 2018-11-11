// Copyright (C) YelloSoft

#include "charm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    start_charm();

    vcenter_string("Hello Charm! Press Escape, q, or Control-C to quit.");

    key k = KEY_UNKNOWN;

    while (k != KEY_ESCAPE && k != KEY_Q) {
        k = get_key();
    }

    end_charm();

    return EXIT_SUCCESS;
}
