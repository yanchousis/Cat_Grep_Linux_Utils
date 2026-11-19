CC=gcc
CHGFLAGS=-Wall -Werror -Wextra -std=c11
FILES_C=mainCat.c cat.c parsingCat.c ../common/common.c
FILES_O=mainCat.o cat.o parsingCat.o common.o

all: my_cat

my_cat: cat_c
	$(CC) $(CHGFLAGS) $(FILES_O) -o my_cat

cat_c:
	$(CC) $(CHGFLAGS) -c $(FILES_C)

test:
	sh testCat.sh

clean:
	rm -rf *.o my_cat myFileTest.txt catFileTest.txt

rebuild: clean my_cat