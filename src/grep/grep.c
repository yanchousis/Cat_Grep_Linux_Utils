#include "grep.h"

void openFile(char const* fileName, char** patterns, char const* flags,
              int countPat, int countF) {
  FILE* file = NULL;

  if (strcmp(fileName, "-") == 0) {
    file = stdin;
    fileName = "(standard input)";
  } else
    file = fopen(fileName, "r");

  if (file) {
    startFillStr(file, patterns, flags, countPat, fileName, countF);

    if (file != stdin) fclose(file);
  } else if (!checkFlag(flags, 's'))
    printf("my_grep: %s: file or directory not exist\n", fileName);
}

void startFillStr(FILE* file, char** patterns, char const* flags, int countPat,
                  char const* f, int countF) {
  int size = 256;
  char* str = calloc(size, sizeof(char));
  int j = 0, countStr = 0, matchStr = 0;
  signed char ch = 0;
  char print = 1, flagC = checkFlag(flags, 'c');

  while (ch != EOF) {
    ch = fgetc(file);
    if (j == size - 1) changeSizeStr(&str, &size);

    if (createStr(ch, str, &j) && !(j == 0 && ch == EOF) && print != 3) {
      ++countStr;
      j = 0;
      print = regexfunc(str, patterns, flags, countPat, f, countF, countStr);

      if (print == 1) {
        ++matchStr;

        if (!checkFlag(flags, 'o') || checkFlag(flags, 'l'))
          print = outputStr(str, f, flags, countStr, countF);

        if (file == stdin && checkFlag(flags, 'l')) ch = EOF;
      }
    }
  }

  if (flagC && !checkFlag(flags, 'l')) {
    if (countF > 1 && !checkFlag(flags, 'h')) printf("%s:", f);

    printf("%d\n", matchStr);
  }

  free(str);
}

char regexfunc(char* str, char** patterns, char const* flags, int countPat,
               char const* f, int countF, int countStr) {
  char print = 0, flagO = checkFlag(flags, 'o');
  char flagV = checkFlag(flags, 'v');

  for (int i = 0; i < countPat && print != 3; ++i) {
    regex_t re;

    if (checkFlag(flags, 'i')) {
      if (regcomp(&re, patterns[i], REG_EXTENDED | REG_NEWLINE | REG_ICASE)) {
        printf("Error regcomp\n");
        print = 2;
      }
    } else {
      if (regcomp(&re, patterns[i], REG_EXTENDED | REG_NEWLINE)) {
        printf("Error regcomp\n");
        print = 2;
      }
    }

    if (print != 2 && flagV) {
      if (regexec(&re, str, 0, NULL, 0))
        print = 1;
      else {
        print = 0;
        i = countPat;
      }
    } else if (print != 2) {
      if (regexec(&re, str, 0, NULL, 0) == 0) print = 1;
    }

    if (print != 2 && flagO && !flagV) {
      print = outputO(str, re, f, flags, countStr, countF);
    }

    regfree(&re);
  }

  return print;
}

char outputO(char* str, regex_t re, char const* f, char const* flags,
             int countStr, int countF) {
  char print = 0;

  char* s = str;
  regmatch_t pmatch[1];
  regoff_t len;
  char stop = 0;

  for (unsigned i = 0; !stop; ++i) {
    if (regexec(&re, s, 1, pmatch, 0) == 0 && print != 3) {
      print = outputStr(str, f, flags, countStr, countF);

      if (!checkFlag(flags, 'l') && !checkFlag(flags, 'c')) {
        len = pmatch[0].rm_eo - pmatch[0].rm_so;
        printf("%.*s\n", (int)len, s + pmatch[0].rm_so);

        s += pmatch[0].rm_eo;
      }

      if (checkFlag(flags, 'l') || checkFlag(flags, 'c')) stop = 1;
    } else
      stop = 1;
  }

  return print;
}

char outputStr(char const* str, char const* f, char const* flags, int countStr,
               int countF) {
  char print = 1, flagC = checkFlag(flags, 'c');
  char flagL = checkFlag(flags, 'l'), flagO = checkFlag(flags, 'o');

  if (countF > 1 && !flagL && !flagC && !checkFlag(flags, 'h')) {
    printf("%s:", f);
  }

  if (flagL) {
    printf("%s\n", f);
    print = 3;
  } else if (!flagC) {
    if (checkFlag(flags, 'n')) printf("%d:", countStr);

    if (!flagO) printf("%s\n", str);
  }

  return print;
}

char createStr(char ch, char* str, int* j) {
  char retVal = 0;

  if (ch != EOF && ch != '\n')
    str[(*j)++] = ch;
  else if (ch == '\n' || ch == EOF) {
    str[*j] = '\0';
    retVal = 1;
  }

  return retVal;
}

void changeSizeStr(char** str, int* size) {
  *size = *size + 128;
  *str = realloc(*str, *size);
}