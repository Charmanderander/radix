/* myip.c  
   A demo program making use of pipe to 
   read output from a child program
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define errquit(msg) { perror(msg); exit(EXIT_FAILURE); }

int main(int argc, char *argv []) 
{
    int fd[2];
    pid_t pid;

    if ( pipe(fd) == -1 ) errquit("pipe");
    pid = fork();
    if ( pid == 0 ) { //child
        dup2(fd[1], 1); //duplicate the writing end of pipe to standard output
        execl("/sbin/ifconfig", "/sbin/ifconfig", NULL);
        errquit("execl ifconfig"); //cannot execl then err
    } else if ( pid > 0 ) { //parent
        close(fd[1]); //so that when child ends, pipe closes
        char mybuf[256], *ip;
        FILE *p = fdopen(fd[0], "r");
        while ( fgets(mybuf,256,p) ) {
           if ( strstr(mybuf, "inet addr:") ) {
               strtok(mybuf, ":");
               ip = strtok(NULL, " ");
               printf("%s\n", ip);
           }
        }
    } 
	return 0;
}
