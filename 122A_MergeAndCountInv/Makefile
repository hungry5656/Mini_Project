CC = g++
DEV = -Wall -Werror

.PHONY: all
all: MergeAndCount.o main

main: main.cpp
	$(CC) $(DEV) -o3 main.cpp -o main

MergeAndCount.o: MergeAndCount.cpp MergeAndCount.h
	$(CC) $(DEV) -c MergeAndCount.cpp

.PHONY: clean
clean:
	rm -f *.o
	rm -f main

.PHONY: update
update:
	make clean
	make all
