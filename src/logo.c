#include "logo.h"

char	generate_numeric_char()
{
	return ((char)(48 + random() % 2));
}

void	reset_settings(int *counter, int keys[], int *row_key)
{
	int i;
	*counter = 0;
	*row_key = 0;
	
	i = 0;
	while (i < KEYS)
		keys[i++] = 0;
}

void	print_iter(int keys[KEYS])
{
	int i;
	int j;
	int k;
	
	i = 0;
	while (i < ARR_ROWS)
	{
		k = 0;
		while (k < ARR_LETTERS)
		{
			j = 0;
			while (j < ARR_COLS)
			{
				if (keys[i] == 1)
					print_static_line(arr[k][i][j]);
				else
					print_colored_symbol(FG_COLOR_GREEN, generate_numeric_char());
				j++;
			}
			k++;
		}
		printf("\n");
		i++;
	}
}

void	print_logo() {
	int counter;
	int row_key;
	int keys[KEYS];
	
	reset_settings(&counter, keys, &row_key);
	while (counter < MAX_COUNTER)
	{
		clean_screen();
		if (counter % DIVIDER == DIVIDER - 1)
		{
			keys[row_key] = 1;
			row_key++;
		}
		print_iter(keys);
		counter++;
		delay(DELAY_VALUE_MMS);
	}
	delay(DELAY_BTWN_ITER);
	printf("\n"); 
}

void	delay(int milli_seconds)
{
	clock_t start_time;
   
	start_time = clock();
	while (clock() < start_time + milli_seconds);
}

int     is_numeric(char symbol)
{
	return (symbol >= '0' && symbol <= '9');
}

void	print_colored_symbol(const char *color, char symbol)
{
	set_color(color);
	printf("%c", symbol);
}

void	print_static_line(char c)
{
	if (is_numeric(c))
		print_colored_symbol(FG_COLOR_WHITE, c);
	else
		printf("%c", EMPTY);
}

void	clean_screen()
{
	printf("\e[1;1H\e[2J");
}

void	set_color(const char *color)
{
	printf("%s", color);
}


int		main(void)
{
	while (1)
		print_logo();
	return (0);
}
