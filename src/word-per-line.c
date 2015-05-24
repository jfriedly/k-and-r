#include <stdio.h>

#define MAX_WORDSIZE 100
#define OUT 0
#define IN 1

int main(int argc, char **argv)
{
	char c;
	char word[MAX_WORDSIZE];
	char *p = word;
	int state = OUT;

	while ((c = getchar()) != EOF) {
		switch (c) {
		case ' ':
		case '\t':
		case '\n':
			if (state == IN) {
				*p = '\0';
				printf("%s\n", word);
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
	return 0;
}
