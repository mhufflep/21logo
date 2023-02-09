#include "logo.h"

inline
char	gen_char(char min, char max) {
	return (min + rand() % (max - min + 1));
}

inline
void 	print_line(int opened[], int idxs[], int idxs_len, int line_num, int offset) {

	int i = 0;
	const int mask = (1 << SYMBOL_WIDTH) - 1;
	while (i < idxs_len)
	{
		const int idx = idxs[i];
		const char line = (symbols[idx] >> offset) & mask;
		
		if (opened[line_num]) {
			print_opened_line(FG_COLOR_WHITE, line);
		} else {
			print_closed_line(FG_COLOR_GREEN);
		}

		i++;
	}
	printf("\n");
}

void	print_logo(int opened[], int idxs[], int idxs_len)
{
	int offset = 32 - SYMBOL_WIDTH;
	for (size_t line = 0; line < SYMBOL_HEIGHT; line++)
	{
		for (size_t sc = 0; sc < SCALE_X; sc++)
		{
			print_line(opened, idxs, idxs_len, line, offset);
		}
		offset -= SYMBOL_WIDTH;
	}
}

void	logo_cycle(int *indices, size_t length) {

	int i = 0;
	int line = 0;
	int opened_lines[SYMBOL_HEIGHT] = { 0 };
	
	while (i < MAX_COUNTER)
	{
		// clears screen
		printf("\e[1;1H\e[2J");

		if (i % DIVIDER == DIVIDER - 1) {
			opened_lines[line] = 1;
			line++;
		}
		print_logo(opened_lines, indices, length);
		i++;
	
		delay(DELAY_BTWN_FRAMES_MS);
	}
	delay(DELAY_BTWN_ITER_MS);
	printf("\n"); 
}

void	delay(int milli_seconds) {
	clock_t start_time = clock();
	while (clock() < start_time + milli_seconds);
}

inline
void	print_opened_line(const char *color, char line) {

	for (size_t i = 0; i < SYMBOL_WIDTH; i++) {
		if ((line >> (SYMBOL_WIDTH - i - 1)) & 0x1) {
			print_symbol(RANDOM_SYMBOL, color);
		} else {
			print_symbol(EMPTY, "");
		}
	}
}

inline
void	print_closed_line(const char *color) {

	for (size_t i = 0; i < SYMBOL_WIDTH; i++) {
		print_symbol(RANDOM_SYMBOL, color);
	}
}

inline 
void	print_symbol(const char c, const char *color) {

	for (size_t i = 0; i < SCALE_Y; i++) {
		if (c == RANDOM_SYMBOL) {
			printf("%s%c", color, gen_char(RANDOM_MIN, RANDOM_MAX));
		} else {
			printf("%s%c", color, c);
		}
	}
}

void	gen_indices(const char *s, int *idxs, size_t len) {
	
	for (size_t i = 0; i < len; i++) {
		if (isnumber(s[i])) {
			idxs[i] = s[i] - '0';
		} else if (isalpha(s[i])) {
			idxs[i] = 10 + toupper(s[i]) - 'A';
		} else {
			// space
			idxs[i] = 36;
		}
	}
}

int		main(int ac, char **av) {

	// Default is "21"
	char *s = (ac < 2 || !av[1][0]) ? "21" : av[1];

	size_t len = strlen(s);
	int *idxs = alloca(len * sizeof(int));
	gen_indices(s, idxs, len);
	srand(time(0));

	while (1) {
		logo_cycle(idxs, len);
	}

	return (0);
}
