WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

a2: a2.o
	$(GCC) a2.o -o a2

a1.o: a2.c
	$(GCC) -c a2.c -o a2.o

clean:
	rm -f *.o a2 
