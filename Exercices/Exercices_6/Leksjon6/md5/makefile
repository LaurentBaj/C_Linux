#
# Generic makefile for compiling and linking more than one source file
#
TARGET = ex4
OBJS = $(TARGET).o md5.o # List object files here
DEPS = md5.h makefile
CFLAGS = -O2

%.o: %.c $(DEPS)
	gcc -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJS)
	gcc -o $@ $^ $(CFLAGS)

.phony: clean
clean:
	rm -f *.o $(TARGET)

