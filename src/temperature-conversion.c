#include <stdio.h>

float convert(float celsius)
{
	return 1.8 * celsius + 32;
}

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
	celsius = upper;
	while (celsius >= lower) {
		fahr = convert(celsius);
		printf("%-10.0f   %-7.1f\n", fahr, celsius);
		celsius = celsius - step;
	}
	return 0;
}
