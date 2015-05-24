#include <stdio.h>

/* print Fahrenheit-Celsius table for 0, 20, ... 300F; floating-point version*/
int main(int argc, char **argv)
{
	float fahr;
	float celsius;
	int lower = 0;		/* lower limit of temperature table */
	int upper = 300;	/* upper limit */
	int step = 20;		/* step size */

	printf("Fahrenheit   Celsius\n");
	printf("--------------------\n");
	fahr = lower;
	while (fahr <= upper) {
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%-10.0f   %-7.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	return 0;
}
