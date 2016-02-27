#include <stdio.h>

/* any:  return the first index of a character in s1 that also appears in s2 */
int any(char s1[], char s2[])
{
	for (int i = 0; s1[i] != '\0'; i++) {
		for (int j = 0; s2[j] != '\0'; j++) {
			if (s1[i] == s2[j])
				return i;
		}
	}
	return -1;
}

int main(int argc, char **argv)
{
	if (argc > 2) {
		printf("Location of first character [%s] in \"%s\"\n",
			argv[2], argv[1]);
		printf("%d\n", any(argv[1], argv[2]));
	} else {
		fprintf(stderr, "Usage:  %s original characters_to_find\n",
			*argv);
		return 1;
	}
	return 0;
}
