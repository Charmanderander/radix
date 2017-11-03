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

    msgid = msgget(MSGKEY,IPC_CREAT|0600);
    if ( msgid < 0 ) err_quit("msgget");

    while ( 1 ) {
        nbytes = msgrcv(msgid,&mybuf,256,1,0);//receives mtype = 1
        if ( nbytes < 0 ) err_quit("msgrcv");
        printf("Message received : %s",mybuf.mtext);
       }
}
