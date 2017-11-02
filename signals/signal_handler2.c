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
    //act.sa_flags = SA_RESTART; //restart system call
    act.sa_flags = 0; //if you dont set SA_RESTART, it will get out of fgets() below 
                      //after handling signal

    if ( sigaction(SIGINT, &act, NULL) == -1 ) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }
    
    int n = 0;
    char buf[128];
    printf("Please enter your input:");
    fflush(stdout);
    fgets(buf, 128, stdin);
    printf("You entered : %s", buf);

}
