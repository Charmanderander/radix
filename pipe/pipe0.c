/* pipe0.c  */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define errquit(msg) { perror(msg); exit(EXIT_FAILURE); }

int main(int argc, char *argv []) 
{
    int fd[2];
    pid_t pid;

    if ( pipe(fd) == -1 ) errquit("pipe");
    pid = fork();
    if ( pid == 0 ) { //child
        char buf[64];
        int n = 1, nbytes;
        while ( n < 6 ) {
            nbytes = snprintf(buf, 64, "child writing n = %d\n", n++);
            write(fd[1], buf, nbytes);
        }
    } else if ( pid > 0 ) { //parent
        close(fd[1]); // closing the writing end of the pipe
        char mybuf[64];
        FILE *p = fdopen(fd[0], "r");
        while ( fgets(mybuf,64,p) ) {
           printf("Parent: %s\n", mybuf);
        }
    } 
	return 0;
}
