.POSIX:
CC     = cc
CFLAGS = -W -O
LDLIBS = -lm

all: example
example: example.o
	$(CC) $(LDFLAGS) -o example example.o $(LDLIBS)
example.o: example.c
clean:
	rm -f example example.o

