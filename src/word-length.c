#include <stdio.h>
#include <string.h>

#include "histogram.h"

#define MAX_WORDSIZE 40
#define OUT 0
#define IN 1

/* Print a histogram showing the word lenths of the input */
int main(int argc, char **argv)
{
	char c;
	char word[MAX_WORDSIZE];
	char *p = word;
	unsigned int lengths[MAX_WORDSIZE];
	size_t length;
	int state = OUT;

	for (int i = 0; i < MAX_WORDSIZE; i++)
		lengths[i] = 0;

	while ((c = getchar()) != EOF) {
		switch (c) {
		case ' ':
		case '\t':
		case '\n':
			if (state == IN) {
				*p = '\0';
				length = strlen(word);
				lengths[length]++;
				p = word;
				state = OUT;
			}
			break;
		default:
			state = IN;
			/*
			 * TODO(jfriedly):  keep track of the word length and
			 * exit with an error if it's > MAX_WORDSIZE
			 */
			*p++ = c;
		}
	}

	/* horizontal_histogram(lengths, MAX_WORDSIZE); */
	vertical_histogram(lengths, MAX_WORDSIZE);

	return 0;
}
