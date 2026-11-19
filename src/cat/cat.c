#include "cat.h"

void openFile(char const* fileName, char const* flags, int* k, char* chPrev) {
  FILE* file = 0;

  if (strcmp(fileName, "-") == 0)
    file = stdin;
  else
    file = fopen(fileName, "r");

  if (file) {
    signed char ch = fgetc(file);

    while (ch != EOF) {
      addFlags(ch, flags, k, file, *chPrev);
      *chPrev = ch;
      ch = fgetc(file);
    }

    if (file != stdin) fclose(file);
  } else
    printf("my_cat: %s: file or directory not exist\n", fileName);
}

void addFlags(char ch, char const* flags, int* k, FILE* file, char chPrev) {
  char flag_V = 0, chNext = 0;
  if (file != stdin) {
    chNext = fgetc(file);
    ungetc(chNext, file);
  }

  if (checkFlag(flags, 's') && ch == '\n' && chPrev == '\n' && chNext == '\n') {
    return;
  }

  if (((checkFlag(flags, 'b') && ch != '\n') ||
       (checkFlag(flags, 'n') && !checkFlag(flags, 'b'))) &&
      chPrev == '\n') {
    printf("%6d\t", (*k)++);
  }

  if (checkFlag(flags, 'T') || checkFlag(flags, 't')) {
    if (ch == '\t') {
      printf("^");
      ch += 64;
    }
    if (checkFlag(flags, 't')) {
      ch = flagV(ch);
      flag_V = 1;
    }
  }

  if (checkFlag(flags, 'E') || checkFlag(flags, 'e')) {
    if (ch == '\n') putchar('$');
    if (checkFlag(flags, 'e') && !flag_V) ch = flagV(ch);
  }

  putchar(ch);
}

char flagV(char ch) {
  if (ch == 127) {
    printf("^");
    ch = '?';
  } else if (ch >= 0 && ch <= 31 && ch != 10 && ch != 9) {
    printf("^");
    ch += 64;
  } else if (ch < -1)
    printf("M-");

  return ch;
}