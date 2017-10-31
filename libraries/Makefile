libcoconut.a : sub1.o sub2.o
	ar rcs libcoconout.a sub1.o sub2.o

clean:
	rm -f *.o *.a

myprog: main.c libcoconut.a
	gcc -o myprog main.c -L./ -lcoconut
