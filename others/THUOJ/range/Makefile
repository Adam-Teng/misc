NAME := $(shell basename $(PWD))

all: $(NAME)
include ../Makefile

run: all
	./$(NAME) < test > test.out

