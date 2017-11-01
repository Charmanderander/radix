CFLAGS = -fPIC

all : libpapaya.so

libpapaya.so : libpapaya-1.0.so
	ln -s libpapaya-1.0.so libpapaya.so
	ln -s libpapaya-1.0.so libpapaya.so.1

libpapaya-1.0.so : sub1.o sub2.o
	gcc $(CFLAGS) -shared -Wl,-soname,libpapaya.so.1 sub1.o sub2.o -o libpapaya-1.0.so

clean : 
	$(RM) *.so* *.o

.PHONY : clean
