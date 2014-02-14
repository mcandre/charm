// Copyright (C) YelloSoft

#include "charm.h"
#include <gc.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static void draw_score(int score) {
  char *m;

  move_cursor(0, 2);
  m = (char *) GC_MALLOC(20 * sizeof(char));
  (void) snprintf(m, 20, "SCORE %04d", score);

  hcenter_string(m);
}

static void draw_arrow(key arrow) {
  move_cursor(0, 4);

  switch (arrow) {
    case KEY_UP:
      hcenter_string("^");
      break;
    case KEY_DOWN:
      hcenter_string("v");
      break;
    case KEY_RIGHT:
      hcenter_string(">");
      break;
    case KEY_LEFT:
      hcenter_string("<");
      break;
    default:;
  }
}

static void draw_hoot(int hoot) {
  move_cursor(0, 6);

  if (hoot == 0) {
    hcenter_string("GOOD!");
  }
  else {
    hcenter_string("BAD! ");
  }
}

int main() {
  int score, delta;

  key arrow, k;

  srand((unsigned int) time(NULL));

  GC_INIT();

  start_charm();

  hcenter_string("DDR: How fast can you play?");

  score = 0;
  delta = 0;

  arrow = KEY_UP + (rand() % 4);

  k = KEY_UNKNOWN;

  while (k != KEY_ESCAPE && k != KEY_Q) {
    draw_score(score);

    draw_arrow(arrow);

    k = get_key();

    delta = (arrow - k);

    if (delta == 0) {
      score++;
    }
    else {
      score--;
    }

    draw_hoot(delta);

    arrow = KEY_UP + (rand() % 4);
  }

  end_charm();

  return 0;
}
