WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

a1: a1.o
	$(GCC) a1.o -o a1

a1.o: a1.c
	$(GCC) -c a1.c -o a1.o

clean:
	rm -f *.o a1 
