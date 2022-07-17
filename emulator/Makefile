.PHONY: run clean test

CFLAGS = -std=c11 -O2
CC = gcc
LD = gcc

logisim: logisim.o
	$(LD) $(LDFLAGS) -o logisim logisim.o

logisim.o: logisim.c
	$(CC) $(CFLAGS) -c -o logisim.o logisim.c

run: logisim
	@./logisim

clean:
	rm -f logisim *.o

test: logisim
	./logisim | ./display.py
