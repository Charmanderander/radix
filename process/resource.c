/* resource.c  */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(int argc, char *argv []) 
{
    struct rusage rsg;

    int n = 1;
    while(n > 0) n++;//until overflow

    if ( getrusage(RUSAGE_SELF, &rsg) == -1 ) {
        perror("getrusage");
        exit(EXIT_FAILURE);
    }
    printf("usermode time taken = %ld.%06ld secs\n", rsg.ru_utime.tv_sec, 
                                                 rsg.ru_utime.tv_usec);

	return 0;
}
