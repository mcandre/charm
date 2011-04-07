#ifndef CHARM_H
#define CHARM_H

#include "gc.h"

#define CHARM_VERSION "0.0.1"

void hide_cursor();
void show_cursor();
void move_cursor(int x, int y);
void clear_screen();
void start_charm();
void end_charm();

/* ... */

#endif