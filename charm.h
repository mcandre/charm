#ifndef CHARM_H
#define CHARM_H

#define CHARM_VERSION "0.0.1"

int get_width();
int get_height();

void hide_cursor();
void show_cursor();

void move_cursor(int x, int y);
void put_char(char c);
void put_string(char *s);
void center_string(char *s);

void clear_screen();

void handle_signal(int signal);
void start_charm();
void end_charm();

// ...

#endif