objects = foo.o bar.o all.o
all: $(objects)

# These files compile via implicit rules
# Syntax - targets ...: target-pattern: prereq-patterns ...
# In the case of the first target, foo.o, the target-pattern matches foo.o and sets the "stem" to be "foo".
# It then replaces the '%' in prereq-patterns with that stem
$(objects): %.o: %.c

all.c:
	echo "int main() { return 0; }" > all.c

%.c:
	touch $@

clean:
	rm -f *.c *.o all


# OUTPUT: 
# echo "int main() { return 0; }" > all.c
# cc    -c -o all.o all.c
# touch foo.c
# cc    -c -o foo.o foo.c
# touch bar.c
# cc    -c -o bar.o bar.c
# cc   all.o foo.o bar.o   -o all