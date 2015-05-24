#include <stdio.h>

#include "histogram.h"

#define ASCII_MAX 128

int main(int argc, char **argv)
{
	char c;
	unsigned int counts[ASCII_MAX];

	for (int i = 0; i < ASCII_MAX; i++)
		counts[i] = 0;

	while ((c = getchar()) != EOF) {
		counts[(unsigned int) c]++;
	}

	horizontal_histogram(counts, ASCII_MAX);

	return 0;
}
