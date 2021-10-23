

CC=clang
CFLAGS=-Wall -g



all: mainapp


mainapp: main.o tools.o
	$(CC) $(CFLAGS) main.o tools.o
	
	
%.o: %.c
	$(CC) $(CLAGS) -c $^
	
	
clean: 
	rm a.out *.o mainapp



