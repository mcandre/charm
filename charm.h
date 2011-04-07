#ifndef CHARM_HEADER
#define CHARM_HEADER

#define CHARM_VERSION "0.0.1"

#include "key.h"

int pos_x;
int pos_y;

int get_width();
int get_height();

void cursor_off();
void cursor_on();

void echo_off();
void echo_on();

void raw_on();
void raw_off();

void move_cursor(int x, int y);
void put_char(char c);
void put_string(char *s);
void center_string(char *s);

void clear_screen();

void handle_signal(int signal);
void start_charm();
void end_charm();

#endif