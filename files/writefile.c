
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

    int fd;
    char mybuf[256];
    int n, nbytes;
    const char filename[] = {"MYFILE.TXT"};

    fd = open(filename, O_CREAT|O_TRUNC|O_WRONLY, 0600);
    if (fd == -1) {
        perror(filename);
        exit(errno);
    }
  
    for ( n = 0; n < 6; n++ ){
        nbytes = sprintf(mybuf, "writing n = %d\n", n);
        write(fd, mybuf, nbytes);
    }

    close(fd);
   
    return 0;
}
