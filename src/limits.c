#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <float.h>

#include "dbg.h"

signed long long min_for_size(short bytes)
{
	short bits = bytes << 3;
	bits--;
	return (signed long long) -pow(2, bits);
}

signed long long max_for_size(short bytes)
{
	short bits = bytes << 3;
	bits--;
	debug("Computing 2 ^ %d: %f", bits, pow(2, bits));
	debug("Subtracting 1: %f", pow(2, bits) - 1);
	debug("Converting to signed long long: %lld", (signed long long) pow(2, bits) - 1);
	return (signed long long) pow(2, bits) - 1;
}

unsigned long long umax_for_size(short bytes)
{
	short bits = bytes << 3;
	return (unsigned long long) pow(2, bits) - 1;
}

void print_headers()
{
	printf("\nValues from headers:\n");
	printf("The minimum signed char is %d\n", SCHAR_MIN);
	printf("The maximum signed char is %d\n", SCHAR_MAX);
	printf("The maximum unsigned char is %u\n", UCHAR_MAX);
	printf("The minimum signed short is %d\n", SHRT_MIN);
	printf("The maximum signed short is %d\n", SHRT_MAX);
	printf("The maximum unsigned short is %u\n", USHRT_MAX);
	printf("The minimum signed int is %d\n", INT_MIN);
	printf("The maximum signed int is %d\n", INT_MAX);
	printf("The maximum unsigned int is %u\n", UINT_MAX);
	printf("The minimum signed long is %ld\n", LONG_MIN);
	printf("The maximum signed long is %ld\n", LONG_MAX);
	printf("The maximum unsigned long is %lu\n", ULONG_MAX);
	printf("The minimum signed long long is %lld\n", LLONG_MIN);
	printf("The maximum signed long long is %lld\n", LLONG_MAX);
	printf("The maximum unsigned long long is %llu\n", ULLONG_MAX);
	printf("The minimum normalized positive float is %e\n", FLT_MIN);
	printf("The maximum float is %e\n", FLT_MAX);
	printf("The minimum normalized positive double is %e\n", DBL_MIN);
	printf("The maximum double is %e\n", DBL_MAX);
	printf("The minimum normalized positive long double is %Le\n",
                LDBL_MIN);
	printf("The maximum long double is %Le\n", LDBL_MAX);
}

void print_calculated()
{
	long four_byte_word;
	long long eight_byte_words[2];
	float *flt_ptr = &four_byte_word;
	double *dbl_ptr = &eight_byte_words;
	long double * ldbl_ptr = &eight_byte_words;
	printf("\nValues calculated:\n");
	printf("The minimum signed char is %lld\n",
                min_for_size(sizeof(char)));
	printf("The maximum signed char is %lld\n",
                max_for_size(sizeof(char)));
	printf("The maximum unsigned char is %llu\n",
                umax_for_size(sizeof(char)));
	printf("The minimum signed short is %lld\n",
                min_for_size(sizeof(short)));
	printf("The maximum signed short is %lld\n",
                max_for_size(sizeof(short)));
	printf("The maximum unsigned short is %llu\n",
                umax_for_size(sizeof(short)));
	printf("The minimum signed int is %lld\n",
                min_for_size(sizeof(int)));
	printf("The maximum signed int is %lld\n",
                max_for_size(sizeof(int)));
	printf("The maximum unsigned int is %llu\n",
                umax_for_size(sizeof(int)));
	printf("The minimum signed long is %lld\n",
                min_for_size(sizeof(long)));
	printf("The maximum signed long is %lld\n",
                max_for_size(sizeof(long)));
	/*
         * Can't figure out any way to calculate this value directly, but -1L
         * also works
         */
	printf("The maximum unsigned long is %lu\n",
                0xffffffffffffffff);
	printf("The minimum signed long long is %lld\n",
                min_for_size(sizeof(long long int)));
	printf("The maximum signed long long is %lld\n",
                max_for_size(sizeof(long long int)));
	printf("The maximum unsigned long long is %lu\n",
                0xffffffffffffffff);
	/*
         * Can't figure out any way to calculate the floating point values,
         * but I looked up the data format and figured out how to represent
         * the smallest and largest normalized values.
         *
         * The first bit in any type of floating point number is always a
         * sign bit, but since we're only interested in normalized numbers,
         * we stick to postitive sign bits.
         *
         * Some of the following bits will be exponent bits, with a bias
         * similar to two's compliment.  For example, in 32-bit single-
         * precision floats, the next 8 bits make up the exponent, but the
         * true exponent is determined by subtracting 127 from this value.
         * The highest and lowest values (128 and -127, respectively, in
         * this example) are reserved for zero, infinities, denormal numbers,
         * and NaN, so the true exponent range in this example is -126 to 127.
         *
         * The rest of the bits form the *significand*, the part after the
         * decimal point.  They're implemented as iterative negative powers
         * of two, so fractions >= 1/2 will have the first bit set, fractions 
         * >= 3/4 will also have the second bit set, fractions >= 7/8 will 
         * also have the third bit set, etc.
         *
         * The smallest normalized floating point number will have a mantissa
         * (exponent) of 1 (to avoid the reserved 0 exponent), and a
         * significand of all zeroes.  Its value will be equal to two raised
         * to the minimum exponent, i.e. 2 ^ -126 for 32-bit floats.
         *
         * The largest floating point number will have a the largest non-
         * reserved mantissa and a significand of all ones.  It's value will
         * be approximately equal to two raised to one more than the maximum
         * exponent, i.e. 2 ^ 128 for 32-bit floats.
         *
         * Note for 32-bit floats that even though the exponent is 8 bits,
         * these are not aligned on a byte boundary, so the exponents below
         * are 0x008 = 1 (biased to 1 - 127 = -126) and 0x7f0 = 254 (biased
         * to 254 - 127 = 127 and bitwise AND'ed with a significand of all
         * ones for 0x7f7).
         */
	four_byte_word = 0x00800000;
	printf("The minimum normalized positive float is %e\n", *flt_ptr);
	four_byte_word = 0x7f7fffff;
	printf("The maximum float is %e\n", *flt_ptr);
        /*
         * For 64-bit doubles, the first bit is the sign bit and the next
         * 11 bits make up the exponent, so it ends up on a convenient half-
         * byte boundary.  0x001 is the smallest normal exponent and 0x7fe
         * is the largest exponent.
         */
	eight_byte_words[0] = 0x0010000000000000;
	printf("The minimum normalized positive double is %e\n", *dbl_ptr);
	eight_byte_words[0] = 0x7fefffffffffffff;
	printf("The maximum double is %e\n", *dbl_ptr);
        /*
         * For 128 bit long doubles, the first bit is the sign bit and the
         * next 15 bits make up the exponent, but that doesn't really
         * explain the values below.  I have no idea why these values work,
         * I just found them by guessing and checking.  The first value ought
         * to be negative 0, and the second follows roughly the right pattern,
         * but the last two bytes seem to be read first, as if there's an
         * endianess problem here.  *shrug*
         */
	eight_byte_words[0] = 0x8000000000000000;
	eight_byte_words[1] = 0x0000000000000000;
	printf("The minimum normalized positive long double is %Le\n", *ldbl_ptr);
	eight_byte_words[0] = 0xffffffffffffffff;
	eight_byte_words[1] = 0xffffffffffff7ffe;
	printf("The maximum long double is %Le\n", *ldbl_ptr);
}

int main(int argc, char **argv)
{
	printf("The minimum for any unsigned type is 0\n");
	print_headers();
	print_calculated();
	return 0;
}
