.PHONY: run clean test

CFLAGS = -Wall -Werror -std=c11 -O2
CC = gcc
LD = gcc

lemu: lemu.o idex.o
	$(LD) $(LDFLAGS) -o lemu lemu.o idex.o

lemu.o: lemu.c lemu.h
	$(CC) $(CFLAGS) -c -o lemu.o lemu.c

idex.o: idex.c lemu.h
	$(CC) $(CFLAGS) -c -o idex.o idex.c

run: lemu
	@./lemu

clean:
	rm -f test lemu *.o

test: lemu
	$(CC) $(CFLAGS) -o test idex.o test.c && ./test
