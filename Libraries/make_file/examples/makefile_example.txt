#Makefile


all: hello 1 2 3

hello: hello.c
	gcc -o hello hello.c

1: Ex1.c
	gcc -o 1 Ex1.c


2: Ex2.c
	gcc -o 2 Ex2.c

3: Ex3.c
	gcc -o 3 Ex3.c



clean: 
	rm -f hello 1 2 3
