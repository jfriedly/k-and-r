#include <stdio.h>

int main(int argc, char **argv)
{
	int spaces = 0;
	int tabs = 0;
	int newlines = 0;
	char c;

	while ((c = getchar()) != EOF) {
		switch (c) {
		case ' ':
			spaces++;
			break;
		case '\t':
			tabs++;
			break;
		case '\n':
			newlines++;
			break;
		}
	}

	printf("Spaces:  %d\n", spaces);
	printf("Tabs:  %d\n", tabs);
	printf("Newlines:  %d\n", newlines);

	return 0;
}
