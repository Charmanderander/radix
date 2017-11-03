// semop0.c
//program to demo lock and unlock of semaphore
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>

#define OURKEY 0x1234
void errquit(char *msg) { perror(msg); exit(1); }

int main(int argc, char * argv[])
{
    int semid = semget(OURKEY,1,0600);
    if ( semid == -1 ) errquit("semget");
    printf("Got Semephore id = %d  \n",semid);    
   
    struct sembuf mybuf;

    while ( 1 ) {
       //try to lock the semaphore
       mybuf.sem_num = 0 ;
       mybuf.sem_op  = -1;
       mybuf.sem_flg = SEM_UNDO;
       if ( semop(semid,&mybuf,1) == -1 ) errquit("semop");
       printf("Got the semaphore, hold for 3 secs\n");
       sleep(3); 
       mybuf.sem_op  = 1;
       if ( semop(semid,&mybuf,1) == -1 ) errquit("semop");
       printf("Release \n");
    }
}
