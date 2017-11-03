/* udpclient0.c  */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>

void errquit(char *msg)
{
	perror(msg);
	exit(1);
}

int main(int argc, char *argv []) 
{

	int sfd;
	struct sockaddr_in peeraddr;

    if ( argc != 2 ) {
		printf("Usage : %s <ip/hostname> \n",argv[0]);
		exit(1);
	}

	//create the socket
	sfd = socket(AF_INET,SOCK_DGRAM,0);
	if ( sfd == -1 ) errquit("socket");


	//set up the ip address and port # to connect to
	peeraddr.sin_family = AF_INET;
	peeraddr.sin_port = htons(34000);

	struct hostent *hs = gethostbyname(argv[1]) ;
	if ( hs == NULL ) {
		printf("Wrong hostname or ip address: %s \n",argv[1]);
		exit(1);
	}
	memcpy(&peeraddr.sin_addr,hs->h_addr_list[0],sizeof(struct in_addr));

    if ( connect(sfd,(struct sockaddr *)&peeraddr,sizeof(peeraddr)) == -1 )
	   	errquit("connect");

	char buf[128];
	int nbytes;
	while ( 1 ) {
		printf("Msg:");
		fflush(stdout);
		nbytes = read(0,buf,128);
		send(sfd,buf,nbytes,0);
		int nbytes = recv(sfd,buf,128,0);
		if ( nbytes == 0 ) break ; //connection ended
		printf("%s",buf);
	}
	close(sfd);
	return 0;
}
