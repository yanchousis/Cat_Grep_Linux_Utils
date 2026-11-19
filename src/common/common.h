#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char filesParsing(char*, char**, int);
char flagsParsing(char const*, char*, int);
char addFlag(char, char*, const char*, unsigned, int);
char checkRepeat(char const*, unsigned, char);
char findFlags(char const*, char*, unsigned);
char checkFlag(char const*, char);