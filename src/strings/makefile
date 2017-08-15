IDIR = ../../inc
CC=g++
CFLAGS = -I$(IDIR)
all: largePal
.PHONY: all

largePal: largePal.o
	$(CC) -o largePal largePal.o
largePal.o: largestPalindrome.cpp
	$(CC) -o largePal.o -c largestPalindrome.cpp

tick: tick.o
	$(CC) -o tick tick.o
tick.o: ticker.cpp
	$(CC) -o tick.o -c ticker.cpp
.PHONY: clean
clean:
	rm -f *.o
