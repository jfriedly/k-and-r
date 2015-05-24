#include <stdio.h>
#include <string.h>

#define MAX_LINE 1000

int main(int argc, char **argv)
{
	char line[MAX_LINE];
	int i;
	int len = 0;

	while (fgets(line, MAX_LINE, stdin) != NULL) {
		len = strlen(line);
		for (i = len - 2; i > 0; i--) {
			if (i != ' ' || i != '\t')
				break;
		}
		if (i < 0)
			continue;
		line[++i] = '\n';
		line[++i] = '\0';
		printf("%s", line);
	}

	return 0;
}
