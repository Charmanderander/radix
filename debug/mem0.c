/* mem0.c  */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void do_work() 
{
    int *arr;
    arr = malloc(100 *sizeof(int));
    //do some work
}

int main(int argc, char *argv []) 
{
    int c;
    char *mptr;
    mptr = malloc(100000);
    
    for ( c = 0; c < 2; c++ ) do_work();

    printf("pid = %d, press enter to continue\n", getpid());
    printf("mptr = %p\n", mptr);
    fgetc(stdin);

	return 0;
}
