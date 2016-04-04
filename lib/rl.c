// Copyright (C) YelloSoft

#include "charm.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
  int message_space, x = 0, y = 0;

  key k;

  char *message;

  start_charm();

  message_space = 3;

  clear_screen();
  move_cursor(x, y);
  blot_char('@');

  k = get_key();

  while (k != KEY_ESCAPE && k != KEY_Q) {
    switch (k) {
    case KEY_UP:
      if (y > 0) {
        y--;
      }

      break;

    case KEY_DOWN:
      if (y < get_height() - message_space - 1) {
        y++;
      }

      break;

    case KEY_RIGHT:
      if (x < get_width() - 1) {
        x++;
      }

      break;

    case KEY_LEFT:
      if (x > 0) {
        x--;
      }

      break;

    default:
      ;
    }

    clear_screen();

    message = (char *) malloc(20 * sizeof(char));

    if (message != NULL) {
      (void) snprintf(message, 20, "Cursor: (%d, %d)", get_x(), get_y());
      move_cursor(0, get_height());
      hcenter_string(message);

      free(message);

      move_cursor(x, y);
      blot_char('@');
    }

    k = get_key();
  }

  end_charm();

  return 0;
}
