CC=gcc
CFLAGS= -g -Wall -std=c99
E = bit_ops
TE = test_bit_ops

all: build
	./$(E)

build: bit_ops.o test_bit_ops.o
	$(CC) -o $(E) $(E).o $(TE).o

bit_ops.o:
	$(CC) $(CFLAGS) -c $(E).c

test_bit_ops.o:
	$(CC) $(CFLAGS) -c $(TE).c

.PHONY: clean
clean:
	rm $(E) $(E).o $(TE).o
