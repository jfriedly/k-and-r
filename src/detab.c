#include <stdio.h>

#include "common.h"

#define MAX_LINE 1000

void detab(char *line)
{
	/* TODO(jfriedly):  make this runtime configurable */
	int spaces_per_tab = 8;
	char *p = line;
	int i = 0;
	int j;
	short remaining;

	for (; *p != '\0'; p++) {
		if (*p == '\t') {
			remaining = spaces_per_tab - i % spaces_per_tab;
			for (j = 0; j < remaining; j++)
				putchar(' ');
			i += j;
		} else {
			putchar(*p);
			i++;
		}
	}
	p = line;
}

/* detab:  convert tabs to spaces, while preserving appearance */
int main(int argc, char **argv)
{
	apply_lines(MAX_LINE, stdin, detab);
	return 0;
}
