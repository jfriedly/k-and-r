#include <stdio.h>

#include "common.h"

#define MAX_LINE 1000

void entab(char *line)
{
	/* TODO(jfriedly):  make this runtime configurable */
	int spaces_per_tab = 8;
	int i = 0;
	int j;
	short remaining;

	for (; line[i] != '\0'; i++) {
		if (line[i] == ' ') {
			remaining = spaces_per_tab - i % spaces_per_tab;
			/*
			 * If we've found a space, check to see if
			 * it's all spaces to the next tab stop
			 */
			for (j = 1; j < remaining; j++) {
				if (line[i + j] != ' ') {
					remaining = 0;
					break;
				}
			}
			/*
			 * If there's only one space to the
			 * next tab stop, leave it as a space
			 */
			if (remaining) {
				i += j - 1;
				line[i] = '\t';
			}
		}
		putchar(line[i]);
	}
}

/* entab:  convert strings of spaces to tabs, while preserving appearance */
int main(int argc, char **argv)
{
	apply_lines(MAX_LINE, stdin, entab);
	return 0;
}
