#include <stdio.h>

/* lower: convert text on stdin to lowercase, character by character */
int main(int argc, char **argv)
{
	int c;
	while ((c = getchar()) != EOF) {
		putchar((c >= 0x41 && c <= 0x5A) ? c + 0x20 : c);
	}

	return 0;
}
