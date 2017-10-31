/* errmsg.c  */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv []) 
{
    int fd;
    const char *filename = { "TESTFILE.TXT" };

    fd = open(filename, O_RDONLY);
    if ( fd == -1 ) {
        
        printf("errno = %d, errmsg= %s\n", errno, sys_errlist[99999]);
        perror("open");
        exit(EXIT_FAILURE);
    }
    printf("Success!\n");
	return 0;
}
