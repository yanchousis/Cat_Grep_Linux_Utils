#include "grep.h"

char patternParsing(char** argv, char** patterns, int count, int* i, char* f) {
  char add = 0;

  if (strcmp(argv[*i], "-e") == 0) {
    ++(*i);
    char* str = calloc(strlen(argv[*i]) + 1, sizeof(char));
    patterns[count] = strcpy(str, argv[*i]);
    add = 1;
    *f = 1;
  } else if (strcmp(argv[*i], "-f") == 0) {
    ++(*i);
    add = regexFromFile(argv[*i], patterns, count);
    *f = 1;
  } else if (argv[*i][0] != '-' && !(*f)) {
    char* str = calloc(strlen(argv[*i]) + 1, sizeof(char));
    patterns[count] = strcpy(str, argv[*i]);
    add = 1;
    *f = 1;
  }

  return add;
}

char regexFromFile(char const* fileName, char** patterns, int count) {
  FILE* file = NULL;
  char add = 0;

  if (strcmp(fileName, "-") == 0)
    file = stdin;
  else
    file = fopen(fileName, "r");

  int size = 256, j = 0;
  char* str = calloc(size, sizeof(char));

  if (file) {
    signed char ch = 0;

    while (ch != EOF) {
      ch = fgetc(file);
      if (j == size - 1) changeSizeStr(&str, &size);

      if (createStr(ch, str, &j) && !(j == 0 && ch == EOF)) {
        char* strcopy = calloc(strlen(str) + 1, sizeof(char));
        j = 0;
        patterns[count++] = strcpy(strcopy, str);
        add += 1;
      }
    }
    if (file != stdin) fclose(file);
  } else
    printf("my_grep: %s: file or directory not exist\n", fileName);

  free(str);

  return add;
}

char findFlags(char const* flag_name, char* flags, unsigned j) {
  char arr[] = {'e', 'i', 'v', 'c', 'l', 'n', 'h', 's', 'f', 'o'};
  int count = sizeof(arr);
  char add = 0;

  if (strlen(flag_name) == 3) {
    add = addFlag(flag_name[1], flags, arr, j, count);

    if (add) ++j;

    add = addFlag(flag_name[2], flags, arr, j, count);
    if (add) ++add;
  } else if (strlen(flag_name) == 2)
    add = addFlag(flag_name[1], flags, arr, j, count);
  else
    add = -1;

  return add;
}