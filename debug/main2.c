#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
    int *nptr;
   
    printf("Begins. pid = %d, Press enter to contine\n", getpid());
    fgetc(stdin);
    nptr = (int *) 0x1000;
    *nptr = 20;

    printf("Done!\n");

    return 0;

}
