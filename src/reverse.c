#include <stdio.h>
#include <string.h>

#define MAX_LINE 1000

char *reverse(char *s)
{
	int len = strlen(s);
	char tmp;
	char *b = s;
	char *e = s + len - 1;
	for (; b < e; b++, e--) {
		tmp = *b;
		*b = *e;
		*e = tmp;
	}
	return s;
}

int main(int argc, char **argv)
{
	char line[MAX_LINE];

	while (fgets(line, MAX_LINE, stdin) != NULL) {
		printf("%s", reverse(line));
	}
	return 0;
}
