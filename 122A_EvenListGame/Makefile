CC = g++
DEV = -Wall -Werror

.PHONY: all
all: linkedList.o main.out

linkedList.o: linkedList.cpp linkedList.h
	$(CC) $(DEV) -c linkedList.cpp

main.out: main.cpp linkedList.o
	$(CC) $(DEV) -o3 main.cpp linkedList.o -o main.out

.PHONY: clean
clean:
	rm -f *.o
	rm -f main.out

.PHONY: update
update:
	make clean
	make all
