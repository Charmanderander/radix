/* busy.c  */
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main(int argc, char *argv []) 
{
    int n;
    struct sched_param param;
    param.sched_priority = 10;

    if ( sched_setscheduler(0, SCHED_RR, &param) == -1 ) {
        perror("SCHED_RR");
        exit(EXIT_FAILURE);
    }
    printf("Successfully running in real time priority\n");

    while ( 1 ) n++;
	return 0;
}
