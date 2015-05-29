#include <stdio.h>

#include "common.h"

/*
 * This function does nothing, but includes lots of weird mixtures of
 * strings, comments, and characters so that this program's source can
 * be used as it's test case
 */
void testcase()
{
	{
		char t0[] = "This is a normal string.";
		/* This is a normal comment */
		char t1[] = "This string contains a comment: /* */";
		/* This comment contains a string: "foo" */
		char t2[] = "This string contains an unclosed comment: /* ";
		/* This comment contains an unclosed string: " */
		char t3[] = "This string contains a character: 'a' ";
		/* This comment contains a character: 'a' */
		char t4[] = "This string contains an unclosed character ' ";
		/* This comment contains an unclosed character ' */
		char t5[] = "This string contains an escaped string double quote: \" ";
		/* This comment contains an escaped double quote \" */
	}
	{
		char t0 = 'a';	/* normal character */
		char t1 = '/';	/* comment opener character */
		char t2 = '*';	/* comment closer character */
		char t3 = '"';	/* string opener / closer character */
		char t4 = '\'';	/* character opener character */
	}
	/*/*/
}

int main(int argc, char **argv)
{
	short state = OUT;
	short prev_state;
	char c;			/* currently examined character */
	char c2;		/* next character (sometimes necessary) */

	while ((c = getchar()) != EOF) {
		prev_state = state;
		parse(&state, &c);

		if (prev_state == OUT && state == IN_COMMENT) {
			c = getchar();	/* consume the star */
			continue;
		} if (prev_state == IN_COMMENT && state == OUT) {
			c = getchar();  /* consume the slash */
			continue;
		}

		if (state != IN_COMMENT)
			putchar(c);
	}

	return 0;
}
