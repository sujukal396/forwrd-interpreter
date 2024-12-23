CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)


forwrd: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o forwrd
