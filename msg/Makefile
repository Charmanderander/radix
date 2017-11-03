#Makefile
CFLAGS= -g -pthread
CXXFLAGS = 
LDLIBS = -lrt
CC = gcc

clean:
	@for fn in * ; \
	do if file $$fn | grep -q 'LSB executable' ; \
	   then echo rm $$fn ; rm -f $$fn;   fi; done
	rm -f core gmon.out *.o


