#include "cat.h"

char findFlags(char const* flagName, char* flags, unsigned j) {
  char arr[] = {'b', 'n', 'e', 't', 's', 'T', 'E', '-'};
  int count = sizeof(arr);
  char add = 0;

  if (flagName[1] == '-')
    add = gnuParsing(flagName, flags, j);
  else if (strlen(flagName) == 2)
    add = addFlag(flagName[1], flags, arr, j, count);
  else
    add = -1;

  return add;
}

char gnuParsing(char const* argv, char* arr_flags, int j) {
  char add = 0;

  if (strcmp(argv, GNU_B) == 0) {
    add = findFlags("-b", arr_flags, j);
  } else if (strcmp(argv, GNU_N) == 0) {
    add = findFlags("-n", arr_flags, j);
  } else if (strcmp(argv, GNU_S) == 0) {
    add = findFlags("-s", arr_flags, j);
  } else {
    add = -1;
  }

  return add;
}