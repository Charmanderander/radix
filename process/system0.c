/* system0.c  */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv []) 
{
    int status;
    status = system("/bin/ls -l");
    if ( status == -1 ) {
        printf("Failed!\n");
    } else {
        if ( WIFEXITED(status) && WEXITSTATUS(status) == 0 ) {
            printf("Success!\n");
        } else {
            printf("Failed!\n");
        }
    }

	return 0;
}
