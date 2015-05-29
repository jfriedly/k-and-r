#include <stdio.h>

#include "common.h"
#include "dbg.h"

/* syntax checker:  find unmatched parentheses, braces, and brackets */
int main(int argc, char **argv)
{
	int brace_depth = 0;
	int paren_depth = 0;
	int bracket_depth = 0;
	int line_count = 1;
	short state = OUT;
	char c;

	while ((c = getchar()) != EOF) {
		parse(&state, &c);

		if (state == OUT) {
			switch (c) {
			case '{':
				brace_depth++;
				debug("incrementing brace count at line %d",
					line_count);
				break;
			case '(':
				debug("incrementing paren count at line %d",
					line_count);
				paren_depth++;
				break;
			case '[':
				bracket_depth++;
				debug("incrementing bracket count at line %d",
					line_count);
				break;
			case '}':
				brace_depth--;
				debug("decrementing brace count at line %d",
					line_count);
				if (brace_depth < 0) {
					printf("Error:  closing unopened brace on line %d.\n",
						line_count);
					brace_depth = 0;
				}
				break;
			case ')':
				paren_depth--;
				debug("decrementing paren count at line %d",
					line_count);
				if (paren_depth < 0) {
					printf("Error:  closing unopened paren on line %d.\n",
						line_count);
					paren_depth = 0;
				}
				break;
			case ']':
				bracket_depth--;
				debug("decrementing bracket count at line %d",
					line_count);
				if (bracket_depth < 0) {
					printf("Error:  closing unopened bracket on line %d.\n",
						line_count);
					bracket_depth = 0;
				}
				break;
			}
		}
		if (c == '\n')
			line_count++;
	}

	if (brace_depth > 0)
		printf("Error:  %d unclosed braces at end of file.\n",
			brace_depth);
	if (paren_depth > 0)
		printf("Error:  %d unclosed parens at end of file.\n",
			paren_depth);
	if (bracket_depth > 0)
		printf("Error:  %d unclosed brackets at end of file.\n",
			bracket_depth);
	debug("State is %d at end of file.\n", state);
	return 0;
}
