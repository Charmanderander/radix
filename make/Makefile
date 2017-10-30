
all: myprog

SUBS = main.o sub1.o
SUBS += sub2.o

CFLAG = -g -02

myprog : $(SUBS)
	gcc $(CFLAGS) -o myprog main.o sub1.o sub2.o

main.o : main.c
	gcc $(CFLAGS) -c main.c

sub1.o : sub1.c
	gcc $(CFLAGS) -c sub1.c

sub2.o : sub2.c
	gcc $(CFLAGS) -c sub2.c

clean:
	rm *.o
