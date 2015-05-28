#include <stdio.h>
#include <string.h>

#include "common.h"

#define MAX_LINE 1000
#define FOUND 0
#define SEARCHING 1

void fold(char *line)
{
	int len = strlen(line);
	short state = FOUND;

	for (int i = len; i > 0; i--) {
		if (i % 80 ==  0)
			state = SEARCHING;
		if (state == SEARCHING) {
			if (line[i] == ' ' || line[i] == '\t') {
				line[i] = '\n';
				state = FOUND;
			}
		}
	}
	printf("%s", line);
}

/* fold:  fold long input lines into shorter ones */
int main(int argc, char **argv)
{
	apply_lines(MAX_LINE, stdin, fold);
	return 0;
}
