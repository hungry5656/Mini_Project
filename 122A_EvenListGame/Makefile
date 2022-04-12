CC = g++
DEV = -Wall -Werror

.PHONY: all
all: linkedList.o main

linkedList.o: linkedList.cpp linkedList.h
	$(CC) $(DEV) -c linkedList.cpp

main: main.cpp linkedList.o
	$(CC) $(DEV) -o3 main.cpp linkedList.o -o main

.PHONY: clean
clean:
	rm -f *.o
	rm -f main

.PHONY: update
update:
	make clean
	make all
