#include "../common/common.h"

#define GNU_B "--number-nonblank"
#define GNU_N "--number"
#define GNU_S "--squeeze-blank"

char gnuParsing(char const*, char*, int);

void openFile(char const*, char const*, int*, char*);
void addFlags(char, char const*, int*, FILE*, char);
char flagV(char);