#include <stdio.h>
#include <string.h>

#define MAX_WORDSIZE 40
#define OUT 0
#define IN 1

/* Print a horizontal histogram */
void horizontal_histogram(unsigned int lengths[])
{
	printf("Length\n");
	for (int i = 1; i < MAX_WORDSIZE; i++) {
		printf("%-6d   ", i);
		for (; lengths[i] > 0; lengths[i]--)
			putchar('#');
		putchar('\n');
	}
}

/* Return maximum value in an array of size_t's */
unsigned int max(unsigned int lengths[])
{
	unsigned int max = 0;
	for (int i = 0; i < MAX_WORDSIZE; i++) {
		if (lengths[i] > max)
			max = lengths[i];
	}
	return max;
}

/* Print a vertical histogram */
void vertical_histogram(unsigned int lengths[])
{
	unsigned int max_length = 0;
	while ((max_length = max(lengths)) > 0) {
		for (int i = 1; i < MAX_WORDSIZE; i++) {
			if (max_length == lengths[i]) {
				printf("## ");
				lengths[i]--;
			} else {
				printf("   ");
			}
		}
		putchar('\n');
	}

	for (int i = 1; i < MAX_WORDSIZE; i++)
		printf("%2d ", i);
	putchar('\n');
}

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

	/* horizontal_histogram(lengths); */
	vertical_histogram(lengths);

	return 0;
}
