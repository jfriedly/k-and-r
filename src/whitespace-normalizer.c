#include <stdio.h>

/* replace a string of one or more spaces with a single space character */
int main(int argc, char **argv)
{
	char c;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			putchar(c);
			while ((c = getchar()) == ' ')
				;
		}
		putchar(c);
	}
	return 0;
}
