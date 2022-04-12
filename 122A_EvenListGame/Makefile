CC = g++
DEV = -Wall -Werror

.PHONY: all
all: main

main: main.cpp linkedList.o
    $(CC) $(DEV) -03 main.cpp linkedList.o -o main

linkedList.o: linkedList.cpp linkedList.h
    $(CC) $(DEV) -c linkedList.cpp

.PHONY: clean
clean:
    rm -f *.o
    rm -f main

.PHONY: update
update:
	make clean
	make all
