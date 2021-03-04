#ifndef HEADER_H
# define HEADER_H
	
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>

const char   *FG_COLOR_BLACK = "\033[0;30m";
const char   *FG_COLOR_RED =	"\033[0;31m";
const char   *FG_COLOR_GREEN = "\033[0;32m";
const char   *FG_COLOR_YELLOW = "\033[0;33m";
const char   *FG_COLOR_BLUE = "\033[0;34m";
const char   *FG_COLOR_MAGENTA = "\033[0;35m";
const char   *FG_COLOR_CYAN = "\033[0;36m";
const char   *FG_COLOR_WHITE = "\033[0;37m";
	
//const char   *FG_COLOR_BEFORE = FG_COLOR_GREEN;
//const char   *FG_COLOR_AFTER = FG_COLOR_WHITE;
const int    DELAY_VALUE_MMS = 7500;
const int    DELAY_BTWN_ITER = 1000000;
const int    MAX_COUNTER = 500;
const int    KEYS = 10;
const int    DIVIDER = MAX_COUNTER / KEYS;
const int    ARR_ROWS = 10;
const int    ARR_COLS = 16;
const int    ARR_LETTERS = 2;
const char    EMPTY = ' ';

const char    arr[ARR_LETTERS][ARR_ROWS][ARR_COLS] = {
           {"222222222222    ", "222222222222    ", "            2222", "            2222", "    22222222    ", "    22222222    ", "2222            ", "2222            ", "    222222222222", "    222222222222" },
           {"        1111    ", "        1111    ", "            1111", "            1111", "            1111", "            1111", "            1111", "            1111", "            1111", "            1111" }
};

void		set_color(const char *color);
void		print_static_line(char c);
void		print_colored_symbol(const char *color, char symbol);
int			is_numeric(char symbol);
void		delay(int milli_seconds); 
void		clean_screen();
char		generate_numeric_char();
void		print_logo();
void		print_iter(int keys[]);

#endif
