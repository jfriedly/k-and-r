#include <stdio.h>

/* squeeze:  delete all characters in s2 from s1 */
char *squeeze(char s1[], char s2[])
{
	int i, j, k;

	for (i = 0; s2[i] != '\0'; i++) {
		for (j = k = 0; s1[j] != '\0'; j++) {
			if (s1[j] != s2[i])
				s1[k++] = s1[j];
		}
		s1[k] = '\0';
	}
	return s1;
}

int main(int argc, char **argv)
{
	if (argc > 2) {
		printf("Squeezing characters [%s] from \"%s\"\n", argv[2],
			argv[1]);
		printf("%s\n", squeeze(argv[1], argv[2]));
	} else {
		fprintf(stderr, "Usage:  %s original characters_to_delete\n",
			*argv);
		return 1;
	}
	return 0;
}
