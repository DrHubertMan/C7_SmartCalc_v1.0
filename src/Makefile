CC = gcc -Wall -Werror -Wextra -std=c11
CFLAGS = -c
OFLAGS = -o

all: test

test:
	$(CC) $(OFLAGS) $@ *.c
	./test

clean:
	rm test

rebuild: clean all

