OBJS=	main.o \
	tilt.o \
	board.o \
	keyboard.o

all:	2048

%.o:	%.c Makefile 2048.h
	gcc -Wall -g -c $<

2048:	$(OBJS)
	gcc -Wall -g -o 2048 $(OBJS)

test_tilt:	test_tilt.o $(OBJS) Makefile 2048.h
	gcc -Wall -g -o test_tilt test_tilt.o

test:	test_tilt
	./test_tilt

clean:
	rm *.o 2048 test_tilt
