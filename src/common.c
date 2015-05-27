#include <stdio.h>

unsigned int u_max(unsigned int counts[], unsigned int array_length)
{
	unsigned int max = 0;
	for (int i = 0; i < array_length; i++) {
		if (counts[i] > max)
			max = counts[i];
	}
	return max;
}

void apply_lines(int max_length, FILE *f, void (*func)(char *line))
{
	char line[max_length];

	while (fgets(line, max_length, f) != NULL)
		func(line);
}
