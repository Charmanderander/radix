/* udpserver0.c  */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <time.h>
#include <string.h>
#include <arpa/inet.h>


void errquit(char *msg)
{
	perror(msg);
	exit(1);
}

int main(int argc, char *argv []) 
{
    int sfd ;
	time_t now;
	struct sockaddr_in myaddr,peeraddr;
	socklen_t socklen = sizeof(peeraddr);

	sfd = socket(AF_INET,SOCK_DGRAM,0);
	if ( sfd == -1 ) errquit("socket");

	//set up the ip address and port # to listen on
	myaddr.sin_family = AF_INET;
	myaddr.sin_port = htons(34000);
	myaddr.sin_addr.s_addr = INADDR_ANY; //listen on all interface

    //now bind to socket
	if ( bind(sfd,(struct sockaddr*)&myaddr,sizeof(myaddr)) == -1 ) 
		errquit("bind");

	//now just wait for data fromclient
    char buf[128];
    while ( 1 ) {
	    int nbytes = recvfrom(sfd,buf,128,0,(struct sockaddr *)&peeraddr,&socklen);
		buf[nbytes] = '\0';
		printf("%s(%d): %s",inet_ntoa(peeraddr.sin_addr),
				ntohs(peeraddr.sin_port),buf);
		time(&now);
		strcpy(buf,asctime(localtime(&now)));
		sendto(sfd,buf,strlen(buf)+1,0,(struct sockaddr *)&peeraddr,socklen);
	}
}
