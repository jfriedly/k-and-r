#include <stdio.h>
#include <string.h>

#include "common.h"

#define MAX_LINE 1000

/* Strip trailing whitespace and remove blank lines */
void strip_trailing_whitespace(char *line)
{
	int i;
	int len = 0;

	len = strlen(line);
	for (i = len - 2; i > -1; i--) {
		if (line[i] != ' ' && line[i] != '\t')
			break;
	}
	if (i < 0)
		return;
	line[++i] = '\n';
	line[++i] = '\0';
	printf("%s", line);
}

int main(int argc, char **argv)
{
	apply_lines(MAX_LINE, stdin, strip_trailing_whitespace);
	return 0;
}
