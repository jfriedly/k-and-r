#include <stdio.h>

void horizontal_histogram(unsigned int counts[], unsigned int array_length)
{
	printf("Length\n");
	for (int i = 0; i < array_length; i++) {
		printf("%-6d   ", i);
		for (; counts[i] > 0; counts[i]--)
			putchar('#');
		putchar('\n');
	}
}

unsigned int max(unsigned int counts[], unsigned int array_length)
{
	unsigned int max = 0;
	for (int i = 0; i < array_length; i++) {
		if (counts[i] > max)
			max = counts[i];
	}
	return max;
}

void vertical_histogram(unsigned int counts[], unsigned int array_length)
{
	unsigned int max_length = 0;
	while ((max_length = max(counts, array_length)) > 0) {
		for (int i = 0; i < array_length; i++) {
			if (max_length == counts[i]) {
				printf("## ");
				counts[i]--;
			} else {
				printf("   ");
			}
		}
		putchar('\n');
	}

	for (int i = 0; i < array_length; i++)
		printf("%3d ", i);
	putchar('\n');
}

