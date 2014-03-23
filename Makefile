OBJS=	main.o \
	tilt.o \
	board.o \
	keyboard.o

all:	2048

%.o:	%.c Makefile 2048.h
	gcc -Wall -g -c $<

2048:	$(OBJS)
	gcc -Wall -g -o 2048 $(OBJS)