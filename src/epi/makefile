IDIR = ../../inc
CC=g++
CFLAGS = -std=c++11 -I$(IDIR)
all: MSL
.PHONY: all

MSL: MSL.o
	$(CC) -o MSL MSL.o
MSL.o: mergeSortedList.cpp
	$(CC) -o MSL.o $(CFLAGS) -c mergeSortedList.cpp

.PHONY: clean
clean:
	rm -f *.o
