#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 1024

/* binsearch:  find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

int fastbinsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	/* The loop exits when high = low - 1 */
	if (high >= 0 && x == v[high])
		return high;
	else
		return -1;
}

int main(int argc, char **argv)
{
	if (argc < 2) {
		fprintf(stderr, "%s: Missing argument times_to_run\n",
			argv[0]);
		return 1;
	}
	int times_to_run = atoi(argv[1]);
	int x = 1023;
	int array[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; i++)
		array[i] = i;

	for (int i = 0; i < times_to_run; i++)
		fastbinsearch(x, array, ARRAY_SIZE);

	return 0;
}
