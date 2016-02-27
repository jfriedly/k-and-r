#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dbg.h"

/* is_valid:  return true if p is a valid position and n a valid number of bits */
int is_valid(short p, short n)
{
	if (p > 8 * sizeof(long) - 1 || p < 0) {
		fprintf(stderr, "Position must be in the interval [0, 63]\n");
		return 0;
	}
	if (n > 8 * sizeof(long) || n < 0) {
		fprintf(stderr, "Number of bytes must in the interval "
			"[0, 64]\n");
		return 0;
	}
	if (p + 1 < n) {
		fprintf(stderr, "Position %d too small to write %d "
			"bits\n", p, n);
		return 0;
	}
	return 1;
}

/* p_to_n_bitmask:  return a bit mask where the n bits starting at p are set */
unsigned long p_to_n_bitmask(short p, short n)
{
	/* Can't bitshift this properly */
	if (n == 0)
		return 0L;
        unsigned long mask = 0xffffffffffffffff;
	debug("mask is 0x%.16lx", mask);
	mask <<= (8 * sizeof(long) - p - 1);
	debug("mask is 0x%.16lx", mask);
	mask >>= (8 * sizeof(long) - p - 1);
	debug("mask is 0x%.16lx", mask);
	mask >>= (p + 1 - n);
	debug("mask is 0x%.16lx", mask);
	mask <<= (p + 1 - n);
	debug("mask is 0x%.16lx", mask);
	return mask;
}

/* invert:  invert the n bits starting at p in x */
unsigned long invert(unsigned long x, short p, short n)
{
	unsigned long mask = p_to_n_bitmask(p, n);
	mask &= x;
	debug("mask is 0x%.16lx", mask);
	x ^= mask;
	debug("x    is 0x%.16lx", x);
	mask = p_to_n_bitmask(p, n) & ~mask;
	return x | mask;
}

/*
 * setbits:  set the n bits beginning at p in x to the rightmost n bits in y
 *
 * Note:  position p is 0-indexed from the right side of the long.  To fill
 * in bytes on a byte-aligned boundary, you must subtract one from your
 * position.
 *
 * Example: 
 * setbits(0x0123456789abcdef 31, 8, 0x00) -> 0x0123456700abcdef
 */
unsigned long setbits(unsigned long x, short p, short n, unsigned long y)
{
	unsigned long mask = p_to_n_bitmask(p, n);
        x &= ~mask;
        mask &= y << (p + 1 - n);
        return x | mask;
}

int main(int argc, char **argv)
{
	if (argc < 2)
		goto err_usage;
	if (!strcmp(argv[1], "setbits")) {
		if (argc < 6)
			goto err_usage;
		unsigned long x = strtol(argv[2], NULL, 0);
		short p = strtol(argv[3], NULL, 0);
		short n = strtol(argv[4], NULL, 0);
		if (!is_valid(p, n))
			return 1;
		unsigned long y = strtol(argv[5], NULL, 0);
		unsigned long answer = setbits(x, p, n, y);
		printf("%ld (0x%.16lx)\n", answer, answer);
	} else if (!strcmp(argv[1], "invert")) {
		if (argc < 5)
			goto err_usage;
		unsigned long x = strtol(argv[2], NULL, 0);
		short p = strtol(argv[3], NULL, 0);
		short n = strtol(argv[4], NULL, 0);
		if (!is_valid(p, n))
			return 1;
		unsigned long answer = invert(x, p, n);
		printf("%ld (0x%.16lx)\n", answer, answer);
	} else {
		goto err_usage;
	}

	return 0;

	err_usage:
		fprintf(stderr, "Usage:  %s setbits  original position "
			"num_bits set\n", *argv);
		fprintf(stderr, "Usage:  %s invert   original position "
			"num_bits\n", *argv);
		return 1;
}
