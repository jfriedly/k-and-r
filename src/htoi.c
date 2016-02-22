#include <stdio.h>

#include "common.h"
#include "dbg.h"

#define MAX_LINE 1000

/*
 * isvalid:  check the input and return the starting index of the hex
 *
 * Input should be a hexadecimal number containing no more than four
 * characters, with an optional prefix of '0x' or '0X'.  Allowable characters
 * are 0-9, a-f, and A-F.
 *
 * Return the index of the start of the hex input, or -1 if the input is
 * invalid.
 */
int isvalid(char *line)
{
	int start = 0;
	if (line[0] == '0') {
		if (line[1] == 'x' || line[1] == 'X') {
			start = 2;
		}
	}
	int i = start;
	for (; line[i] != '\0'; i++) {
		switch (line[i]) {
		case '0' :
		case '1' :
		case '2' :
		case '3' :
		case '4' :
		case '5' :
		case '6' :
		case '7' :
		case '8' :
		case '9' :
		case 'a' :
		case 'b' :
		case 'c' :
		case 'd' :
		case 'e' :
		case 'f' :
		case 'A' :
		case 'B' :
		case 'C' :
		case 'D' :
		case 'E' :
		case 'F' :
			i++;
			break;
		default:
			fprintf(stderr, "%s: not valid hex\n", line);
			return -1;
		}
	}

	if (i - start > 4) {
		fprintf(stderr, "%s: too long for 32-bit float\n",
			line);
		return -1;
	}

	return start;
}

void htoi(char *line)
{
	int start = 0;
	line = strip_trailing_whitespace(line);
	if (line == NULL)
		return;
	if (line[0] == '0') {
		if (line[1] == 'x' || line[1] == 'X') {
			start = 2;
		}
	}

	int i = start;
	int value = 0;
	for (; line[i] != '\0'; i++) {
		value <<= 4;
		switch (line[i]) {
		case '0' :
			value |= 0x0;
			break;
		case '1' :
			value |= 0x1;
			break;
		case '2' :
			value |= 0x2;
			break;
		case '3' :
			value |= 0x3;
			break;
		case '4' :
			value |= 0x4;
			break;
		case '5' :
			value |= 0x5;
			break;
		case '6' :
			value |= 0x6;
			break;
		case '7' :
			value |= 0x7;
			break;
		case '8' :
			value |= 0x8;
			break;
		case '9' :
			value |= 0x9;
			break;
		case 'A' :
		case 'a' :
			value |= 0xa;
			break;
		case 'B' :
		case 'b' :
			value |= 0xb;
			break;
		case 'C' :
		case 'c' :
			value |= 0xc;
			break;
		case 'D' :
		case 'd' :
			value |= 0xd;
			break;
		case 'E' :
		case 'e' :
			value |= 0xe;
			break;
		case 'F' :
		case 'f' :
			value |= 0xf;
			break;
		default:
			fprintf(stderr, "%s: not valid hex\n", line);
			return;
		}
	}

	if (i - start > 4) {
		fprintf(stderr, "%s: too long for 32-bit float\n",
			line);
		return;
	}
	printf("%d\n", value);
}


int main(int argc, char** argv)
{
	apply_lines(MAX_LINE, stdin, htoi);
	return 0;
}
