
all : myprog

myprog : main.c papaya
	gcc -o myprog main.c -Ipapaya -Lpapaya -lpapaya

papaya : 
	make -C papaya

clean :
	$(RM) myprog
	make -C papaya clean

.PHONY : all papaya clean
