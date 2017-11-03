/* shmwr.c  */
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHMKEY 0x98765
#define MEMSIZE 4096
#define errquit(msg) { perror(msg); exit(EXIT_FAILURE);}

int main(int argc, char *argv []) 
{
    int shmid = shmget(SHMKEY, MEMSIZE, 0600 | IPC_CREAT);
    if ( shmid == -1 ) errquit("shmget");
    printf("shmid %d created!\n", shmid);

    char *addr = shmat(shmid, NULL, 0);
    if ( addr == (void *)-1 ) errquit("shmat");

    int n = 1;
    while ( 1 ) {
        printf("%s\n", addr);
        sleep(1);
    }
}
