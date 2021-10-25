#  -*- Makefile -*- 

all: main 

main: main.o lib.a
	gcc main.o lib.a -o main

main.o: main.c
	gcc -c main.c

clean:
	rm -f main