#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

/* getline:  read a line into s, return length */
int getline(char s[], int lim)
{
	int c;
	int i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

int main(int argc, char **argv)
{
	int len;
	int max = 0;
	char c;
	char line[MAXLINE];
	char longest[MAXLINE];

	while ((len = getline(line, MAXLINE)) > 0) {
		if (len == MAXLINE - 1) {
			while ((c = getchar()) != EOF && c != '\n')
				len++;
		}
		if (len > max) {
			max = len;
			strcpy(longest, line);
		}
	}

	if (max > 0)
		printf("%s", longest);
	return 0;
}
