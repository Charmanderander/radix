/* exec0.c  */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv []) 
{
    pid_t pid;
    int status;

    pid = fork();
    if ( pid == 0 ) {
        execl("/bin/ls", "/bin/ls", "-l", NULL);
        perror("execl"); //if code reach here, execl had failed
    } else if ( pid > 0 ) {
        wait(&status);
        if ( WIFEXITED(status) && WEXITSTATUS(status) == 0 ) {
            printf("Success!\n");
        } else {
            printf("Failed!\n");
        }
    }

	return 0;
}
