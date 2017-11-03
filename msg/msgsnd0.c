/* This is a sample program that demonstrate the use
   of message queues.
   This program receives data from the message queue.
   There is another program that sends data to the queue.
*/ 
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MSGKEY 0x12345

void err_quit(char *msg)
{
    perror(msg);
    exit(1);
}

struct msgbuf {
       long mtype;
       char mtext[256]; };

int main()
{
    int msgid,nbytes;
    struct msgbuf mybuf;

    msgid = msgget(MSGKEY,0600);
    if ( msgid < 0 ) err_quit("msgget");
	mybuf.mtype = 1;
    while ( 1 ) {
		printf("msg>");
		fflush(stdout);
		nbytes = read(0,mybuf.mtext,256);
		mybuf.mtext[nbytes] = '\0';
        nbytes = msgsnd(msgid,&mybuf,256,0);
       }
}
