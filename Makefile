WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

a4: a4.o
	$(GCC) a4.o -o a4

a4.o: a4.c
	$(GCC) -c a4.c -o a4.o

clean:
	rm -f *.o a4 
