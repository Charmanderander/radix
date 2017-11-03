/* mmapreader.c  */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>
#include <unistd.h>

#define SHAREFILE "ShareFile"
#define FSIZE 4096

#define errquit(msg) { perror(msg); exit(errno); }

int main(int argc, char *argv []) 
{

    int fd;
    char *addr;
    int n = 0;

    fd = shm_open(SHAREFILE, O_RDWR, 0600);
    if ( fd == -1 ) errquit(SHAREFILE);

    addr = mmap(NULL, FSIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if ( addr == MAP_FAILED ) errquit("mmap");

    while ( 1 ) {
        printf("%s", addr);
        sleep(1);
    }

	return 0;
}
