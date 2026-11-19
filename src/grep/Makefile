CC=gcc
CHGFLAGS=-Wall -Werror -Wextra -std=c11
FILES_C=mainGrep.c grep.c parsingGrep.c ../common/common.c
FILES_O=mainGrep.o grep.o parsingGrep.o common.o

all: my_grep

my_grep: grep_c
	$(CC) $(CHGFLAGS) $(FILES_O) -o my_grep

grep_c:
	$(CC) $(CHGFLAGS) -c $(FILES_C)

test:
	sh testGrep.sh

clean:
	rm -rf *.o my_grep myFileTest.txt grepFileTest.txt

rebuild: clean my_grep