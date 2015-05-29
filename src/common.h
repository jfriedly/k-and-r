#ifndef common_h
#define common_h

enum states { OUT, IN_STRING, IN_CHAR, IN_COMMENT, IN_STRING_ESCAPED,
	IN_CHAR_ESCAPED };

/* Return maximum value in an array of unsigned ints */
unsigned int u_max(unsigned int counts[], unsigned int array_length);
/* Iterate over lines, applying a function to each */
void apply_lines(int max_length, FILE *f, void (*func)(char *line));
/* Read a C program and update a state variable. */
void parse(short *state, char *c);
#endif /* common_h */
