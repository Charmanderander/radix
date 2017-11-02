/* blocksig.c  */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv []) 
{
    sigset_t myset;
    sigemptyset(&myset);
    sigaddset(&myset, SIGINT); //adding SIGINT to the set to block

    sigprocmask(SIG_BLOCK, &myset, NULL); //block the signal in myset

    int n = 1;

    while ( n++ < 10 ) {
        printf("Signal for Ctrl-C is blocked, n = %d\n", n);
        sleep(1);
    } 

    sigprocmask(SIG_UNBLOCK, &myset, NULL); //remove SIGINT from the blocked set
    printf("Done!\n");

	return 0;
}
