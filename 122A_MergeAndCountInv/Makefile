CC = g++
DEV = -Wall -Werror

.PHONY: all
all: MergeAndCount.o main.out

MergeAndCount.o: MergeAndCount.cpp MergeAndCount.h
	$(CC) $(DEV) -c MergeAndCount.cpp

main.out: main.cpp MergeAndCount.o
	$(CC) $(DEV) -o3 main.cpp MergeAndCount.o -o main.out

.PHONY: clean
clean:
	rm -f *.o
	rm -f main.out

.PHONY: update
update:
	make clean
	make all
