OBJS=	board.o \
	keyboard.o

all:	2048

%.o:	%.c Makefile 2048.h
	gcc -Wall -g -c $<

2048:	main.o $(OBJS)
	gcc -Wall -g -o 2048 main.o $(OBJS)

test:	test.o
	gcc -Wall -g -o test test.o $(OBJS)
