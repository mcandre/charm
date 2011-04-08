#ifndef CHARM_HEADER
#define CHARM_HEADER

#define CHARM_VERSION "0.0.1"

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

#define ESCAPE_CHAR '\x1b'

typedef enum {
	KEY_A,
	KEY_B,
	KEY_C,
	KEY_D,
	KEY_E,
	KEY_F,
	KEY_G,
	KEY_H,
	KEY_I,
	KEY_J,
	KEY_K,
	KEY_L,
	KEY_M,
	KEY_N,
	KEY_O,
	KEY_P,
	KEY_Q,
	KEY_R,
	KEY_S,
	KEY_T,
	KEY_U,
	KEY_V,
	KEY_W,
	KEY_X,
	KEY_Y,
	KEY_Z,

	// ...

	KEY_UNKNOWN
} key;

key get_key();

#endif