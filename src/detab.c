#include <stdio.h>

#define MAX_LINE 1000

/* detab:  convert tabs to spaces */
int main(int argc, char **argv)
{
	/* TODO(jfriedly):  make this runtime configurable */
	int spaces_per_tab = 8;
	char line[MAX_LINE];
	char *p = line;
	int i;
	int j;

	while (fgets(line, MAX_LINE, stdin) != NULL) {
		i = 0;
		for (; *p != '\0'; p++) {
			if (*p == '\t') {
				for (j = 0; j < spaces_per_tab - i % spaces_per_tab; j++)
					putchar(' ');
				i += j;
			} else {
				putchar(*p);
				i++;
			}
		}
		p = line;
	}
	return 0;
}
