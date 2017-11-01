/* daemon0.c  */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv []) 
{
    pid_t pid;

    pid = fork();
    if ( pid == 0 ) { 
        setsid(); 
        sleep(120); //stays in memory for 120 secs, to simulate background work
    }

	return 0;
}
