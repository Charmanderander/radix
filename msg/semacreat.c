// semacreat.c
//create the samaphore
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define OURKEY 0x1234
void errquit(char *msg) { perror(msg); exit(1); }
//create a semaphore and preset its value
int main(int argc, char * argv[])
{
    if ( argc < 2 ) {
        printf("Usage : %s <preset val> \n",argv[0]);
        exit(1);
    }

    int preset = atoi(argv[1]);
    if ( preset < 1 ) {
        printf("Wrong preset %s \n",argv[1]);
        exit(1);
    }

    int semid = semget(OURKEY,1,IPC_CREAT|0600);
    if ( semid == -1 ) errquit("semget");
    printf("Semephore id = %d  Created \n",semid);    
    
    union semun { int val ;} myun;
    myun.val = preset;

    if (semctl(semid,0,SETVAL,myun) == -1 ) errquit("semctl");
    printf("semaphore preset to %d\n",preset);

}
