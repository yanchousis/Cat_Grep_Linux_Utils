#include <regex.h>

#include "../common/common.h"

char patternParsing(char**, char**, int, int*, char*);
void openFile(char const*, char**, char const*, int, int);
char regexfunc(char*, char**, char const*, int, char const*, int, int);
char createStr(char, char*, int*);
void changeSizeStr(char**, int*);
void startFillStr(FILE*, char**, char const*, int, char const*, int);
char outputStr(char const*, char const*, char const*, int, int);
char regexFromFile(char const*, char**, int);
char outputO(char*, regex_t, char const*, char const*, int, int);