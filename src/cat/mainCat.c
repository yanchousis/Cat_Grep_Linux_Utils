#include "cat.h"

int main(int argc, char** argv) {
  char* flags = calloc(argc, sizeof(char));
  char** files = calloc(argc, sizeof(char*));
  int countFiles = 0, countFlags = 0;
  int kStr = 1;
  char chPrev = '\n';

  for (int i = 1; i < argc; ++i) {
    countFiles += filesParsing(argv[i], files, countFiles);
    char k = flagsParsing(argv[i], flags, countFlags);

    if (k == -1)
      printf("my_cat: invalid option \"%s\"\n", argv[i]);
    else
      countFlags += k;
  }

  if (countFiles == 0)
    openFile("-", flags, &kStr, &chPrev);
  else
    for (int i = 0; i < countFiles; ++i)
      openFile(files[i], flags, &kStr, &chPrev);

  free(flags);
  free(files);
  flags = NULL;
  files = NULL;

  return 0;
}