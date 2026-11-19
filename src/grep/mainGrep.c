#include "grep.h"

int main(int argc, char** argv) {
  char* flags = calloc(argc, sizeof(char));
  char** files = calloc(argc, sizeof(char*));
  char** patterns = calloc(argc, sizeof(char*));
  int countFiles = 0, countFlags = 0, countPatterns = 0;
  char firstData = 0;

  for (int i = 1; i < argc; ++i) {
    char k = flagsParsing(argv[i], flags, countFlags);
    if (k == -1)
      printf("my_grep: invalid option \"%s\"\n", argv[i]);
    else
      countFlags += k;
  }
  if (checkFlag(flags, 'e') || checkFlag(flags, 'f')) firstData = 1;

  for (int i = 1; i < argc; ++i) {
    char addpat = patternParsing(argv, patterns, countPatterns, &i, &firstData);
    countPatterns += addpat;

    if (firstData && !addpat)
      countFiles += filesParsing(argv[i], files, countFiles);
  }

  if (countFiles == 0)
    openFile("-", patterns, flags, countPatterns, countFiles);
  else
    for (int i = 0; i < countFiles; ++i)
      openFile(files[i], patterns, flags, countPatterns, countFiles);

  free(flags);
  free(files);
  for (int i = 0; i < countPatterns; ++i) {
    free(patterns[i]);
  }
  free(patterns);
  flags = NULL;
  files = NULL;
  patterns = NULL;

  return 0;
}