#include <stdio.h>

int main(int argc, char **argv)
{
	printf("hello, world!\n");
/*
 * First version; doesn't work because printf format evaluation is
 * apparently done at compile time:
 * char s[9];
 * for (int i='a'; i <= 'z'; i++) {
 * 	sprintf(s, "\\\\%c: \\%c\n", i, i);
 * 	printf(s);
 * }
 */
	printf("\\a: \a\n");
	printf("\\b: \b\n");
	printf("\\c: \c\n");
	printf("\\d: \d\n");
	printf("\\e: \e\n");
	printf("\\f: \f\n");
	printf("\\g: \g\n");
	printf("\\h: \h\n");
	printf("\\i: \i\n");
	printf("\\j: \j\n");
	printf("\\k: \k\n");
	printf("\\l: \l\n");
	printf("\\m: \m\n");
	printf("\\n: \n\n");
	printf("\\o: \o\n");
	printf("\\p: \p\n");
	printf("\\q: \q\n");
	printf("\\r: \r\n");
	printf("\\s: \s\n");
	printf("\\t: \t\n");
	printf("\\u00bc (Unicode): \u00bc\n");
	printf("\\v: \v\n");
	printf("\\w: \w\n");
	printf("\\x78 (hex): \x78\n");
	printf("\\y: \y\n");
	printf("\\z: \z\n");
	return 0;
}
