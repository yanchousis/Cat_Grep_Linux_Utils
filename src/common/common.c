#include "common.h"

char filesParsing(char* argv, char** files, int j) {
  char retVal = 0;

  if (argv[0] != '-' || strcmp(argv, "-") == 0) {
    files[j] = argv;
    retVal = 1;
  }

  return retVal;
}

char flagsParsing(char const* argv, char* flags, int j) {
  char retVal = 0;

  if (argv[0] == '-' && strcmp(argv, "-") != 0)
    retVal = findFlags(argv, flags, j);

  return retVal;
}

char addFlag(char name, char* flags, const char* arr, unsigned j, int count) {
  char add = 0;

  for (int i = 0; i < count; ++i) {
    char repeat = 0;

    if (arr[i] == name && !(repeat = checkRepeat(flags, j, arr[i]))) {
      flags[j++] = arr[i];
      flags[j] = '\0';
      add = 1;
    }

    if (i == count - 1 && !add) add = -1;
    if (repeat == 1) i = count;
  }

  return add;
}

char checkRepeat(char const* arr, unsigned jFlag, char repeat) {
  char retVal = 0;

  for (unsigned i = 0; i < jFlag; ++i) {
    if (arr[i] == repeat) {
      retVal = 1;
    }
  }

  return retVal;
}

char checkFlag(char const* flags, char flag) {
  char retVal = 0;

  for (int i = 0; flags[i] != '\0'; ++i) {
    if (flags[i] == flag) retVal = 1;
  }

  return retVal;
}