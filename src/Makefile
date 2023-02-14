CC = gcc -Wall -Werror -Wextra
CFLAGS = -c
OFLAGS = -o

all: test

test:
	$(CC) $(OFLAGS) test.out *.c
	./test.out

clean:
	rm *.out

rebuild: clean all