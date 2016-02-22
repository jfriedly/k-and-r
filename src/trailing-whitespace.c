#include <stdio.h>

#include "common.h"

#define MAX_LINE 1000

void print_stripped(char *line)
{
	char *stripped = strip_trailing_whitespace(line);
	if (stripped != NULL)
		printf("%s\n", stripped);
}

int main(int argc, char **argv)
{
	apply_lines(MAX_LINE, stdin, print_stripped);
	return 0;
}
