CC = gcc -Wall -Werror -Wextra -std=c11 -fsanitize=address
CFLAGS = -c
OFLAGS = -o
TARGET = smartcalc
SRC = $(shell find . -maxdepth 1 -name "*.c")
OBJECT = $(SRC:.c=.o)
DEBUG = -g

all: $(TARGET)

$(TARGET): $(OBJECT)
	$(CC) $(OFLAGS) $@ $(OBJECT)
	./$@

%.o: %.c
	$(CC) $(CFLAGS) $< $(OFLAGS) $@

clean:
	rm $(TARGET) $(OBJECT)

rebuild: clean all

clang:
	cp ../materials/linters/.clang-format .
	clang-format -n *.c
	rm .clang-format

.PHONY: all clean rebuild clang