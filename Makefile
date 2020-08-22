CC := gcc

CFLAGS  := -O2 -Wextra -Wall

test: clean
	$(CC) libgetkey.c test.c $(FLAGS) -DNEED_TERM -o test

clean:
	@rm test
