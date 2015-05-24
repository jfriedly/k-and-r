#include <stdio.h>
#include <string.h>

#define MAX_LINE 1000

int main(int argc, char **argv)
{
	char line[MAX_LINE];

	while (fgets(line, MAX_LINE, stdin) != NULL) {
		if (strlen(line) > 80)
			printf("%s", line);
	}
	return 0;
}
