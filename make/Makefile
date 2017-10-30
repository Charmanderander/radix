
all: myprog

SUBS = main.o sub1.o
SUBS += sub2.o

myprog : $(SUBS)
	gcc $(CFLAGS) -o myprog $(SUBS)

%.o : %.c
	gcc $(CFLAGS) -c $<

clean:
	rm *.o
	rm myprog
