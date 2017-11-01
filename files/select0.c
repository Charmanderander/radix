/* select0.c  */
/* using select to poll the keyboard for input, timeout to 10sec */

#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>

int main(int argc, char *argv []) 
{
    fd_set myset;
    FD_ZERO(&myset);
    FD_SET(0, &myset); //add stdin to myset

    struct timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    char name[64];
    printf("Please enter your name within 10sec:");
    fflush(stdout);

    int ret = select(1, &myset, NULL, NULL, &timeout);
    if ( ret == 0 ) {
       printf("Timeout!\n");
    } else if ( ret > 0 ) {
        fgets(name, 64, stdin);
        printf("You have entered: %s", name);
    }

	return 0;
}
