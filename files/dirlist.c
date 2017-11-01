#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

int main(int argc, char *argv[])
{

    DIR *mydir;
    struct dirent *dentry;

    mydir = opendir(".");

    if ( mydir == NULL ){
        perror("opendir");
        exit(errno);
    }

    while ( dentry = readdir(mydir) ) {
        printf("%s\n", dentry->d_name);
    }

    closedir(mydir);

    return 0;

}
