/* signal_handler.c  */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void myhandler(int signum) 
{
    static int count;
    printf("Signal# %d was trigger %d times\n",signum, ++count);
}

int main(int argc, char *argv []) 
{
    struct sigaction act;

    act.sa_handler = myhandler;
    sigemptyset( &act.sa_mask);
    act.sa_flags = SA_RESTART; //restart system call

    if ( sigaction(SIGINT, &act, NULL) == -1 ) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    int n = 0;
    while ( n++ < 30 ) {
        sleep(1);
        printf("n = %d\n", n);
    }


}
