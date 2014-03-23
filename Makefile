OBJS=	main.o \
	keyboard.o

all:	2048

%.o:	%.c
	gcc -Wall -g -c $<

2048:	$(OBJS)
	gcc -Wall -g -o 2048 $(OBJS)