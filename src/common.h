#ifndef common_h
#define common_h

/* Return maximum value in an array of unsigned ints */
unsigned int u_max(unsigned int counts[], unsigned int array_length);
/* Iterate over lines, applying a function to each */
void apply_lines(int max_length, FILE *f, void (*func)(char *line));
#endif /* common_h */
