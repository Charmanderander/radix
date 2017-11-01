/* mmaprd.c  */
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

const char * SHAREFILE = "SHAREFILE.DAT";
const int MAPSIZE = 4096;

#define errquit(msg) {perror(msg); exit(EXIT_FAILURE); }

int main(int argc, char *argv []) 
{

    char *addr;

    int fd = open(SHAREFILE, O_RDWR, 0600);
    if ( fd == -1 ) errquit(SHAREFILE);

    if ( ftruncate(fd, MAPSIZE) == -1 ) errquit(SHAREFILE);

    addr = mmap(NULL, MAPSIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if ( addr == MAP_FAILED ) errquit("mmap");

    while ( 1 ) {
        printf("%s\n", addr);
        sleep(2);
    }
	return 0;
}
