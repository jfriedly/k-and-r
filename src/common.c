#include <stdio.h>
#include <string.h>

#include "common.h"

unsigned int u_max(unsigned int counts[], unsigned int array_length)
{
	unsigned int max = 0;
	for (int i = 0; i < array_length; i++) {
		if (counts[i] > max)
			max = counts[i];
	}
	return max;
}

char *strip_trailing_whitespace(char *line)
{
	int i;
	int len = 0;

	len = strlen(line);
	for (i = len - 2; i > -1; i--) {
		if (line[i] != ' ' && line[i] != '\t')
			break;
	}
	if (i < 0)
		return NULL;
	line[++i] = '\0';
	return line;
}


void apply_lines(int max_length, FILE *f, void (*func)(char *line))
{
	char line[max_length];

	while (fgets(line, max_length, f) != NULL)
		func(line);
}

void parse(short *state, char *c)
{
	char c2; /* Next character.  Will always be pushed back onto stdin */

	switch (*c) {
	case '/':
		if (*state == OUT) {
			if ((c2 = getchar()) == '*')
				*state = IN_COMMENT;
			ungetc(c2, stdin);
		}
		break;
	case '*':
		if (*state == IN_COMMENT) {
			if ((c2 = getchar()) == '/')
				*state = OUT;
			ungetc(c2, stdin);
		}
		break;
	case '\\':
		if (*state == IN_STRING) {
			*state = IN_STRING_ESCAPED;
		} else if (*state == IN_CHAR) {
			*state = IN_CHAR_ESCAPED;
		}
		break;
	case '"':
		if (*state == OUT || *state == IN_STRING_ESCAPED)
			*state = IN_STRING;
		else if (*state == IN_STRING)
			*state = OUT;
		break;
	case '\'':
		if (*state == OUT || *state == IN_CHAR_ESCAPED)
			*state = IN_CHAR;
		else if (*state == IN_CHAR)
			*state = OUT;
		break;
	default:
		if (*state == IN_STRING_ESCAPED)
			*state = IN_STRING;
		if (*state == IN_CHAR_ESCAPED)
			*state = IN_CHAR;
	}
}
