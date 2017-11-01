/* notify0.c  */
#include <stdio.h>
#include <stdlib.h>
#include <sys/inotify.h>
#include <errno.h>
#include <unistd.h>

//watching FILE1 and FILE2 for open

#define errquit(msg) { perror(msg); exit(errno); }
int main(int argc, char *argv []) 
{
    int fd = inotify_init();
    if ( fd == -1 ) errquit("inotify_init");

    int f1w = inotify_add_watch(fd, "FILE1", IN_OPEN);
    if ( f1w == -1 ) errquit("add_watch 1");

    int f2w = inotify_add_watch(fd, "FILE2", IN_OPEN);
    if ( f2w == -1 ) errquit("add_watch 2");

    struct inotify_event evt;

    int nbytes = read(fd, &evt, sizeof evt);
    if ( nbytes == -1 ) errquit("read");

    if ( evt.wd == f1w ) 
        printf("FILE1 was open!\n");
    else if ( evt.wd == f2w )
        printf("FILE2 was open!\n");

	return 0;
}
