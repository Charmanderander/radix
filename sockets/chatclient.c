/* tcpclient0.c  */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <netdb.h>
#include <string.h>

#define MYPORT 45000

#define errquit(msg) { perror(msg); exit(EXIT_FAILURE); }

int main(int argc, char *argv []) 
{

    if ( argc < 2 ) {
        fprintf(stderr, "Usage: %s <ip/hostname>", argv[0]);
        exit(EXIT_FAILURE);
    }


    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if ( sockfd == -1 ) errquit("socket");

    struct sockaddr_in peeraddr;
    socklen_t peerlen = sizeof(peeraddr);

    peeraddr.sin_family = AF_INET;
    peeraddr.sin_port   = htons(MYPORT);

    /* 
    if ( inet_aton(argv[1], &peeraddr.sin_addr) == 0 ) {
        fprintf(stderr, "Invalid ip address: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    */

    struct hostent *hent= gethostbyname(argv[1]);
    if ( hent == NULL ) { 
        fprintf(stderr, "Invalid address/hostname: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    memcpy(&peeraddr.sin_addr, hent->h_addr_list[0], sizeof(struct in_addr));

    if ( connect(sockfd, (struct sockaddr*)&peeraddr, peerlen) == -1 )
        errquit("connect");

    int n = 0, nbytes;
    char buf[256];
    fd_set myset;

    while ( 1 ) {
        FD_ZERO(&myset);
        FD_SET(0, &myset);
        FD_SET(sockfd, &myset);

        int res = select(sockfd+1, &myset, NULL, NULL, NULL); 
        if ( res == -1 )  
            errquit("select");
        
        if ( res > 0 ) {
            if ( FD_ISSET(sockfd, &myset) ){
                nbytes = read(sockfd, buf, 256);
                if ( nbytes == 0 || nbytes == -1 ) break;
                write(1, buf, nbytes);
            }
            if ( FD_ISSET(0, &myset) ) {
                nbytes = read(0, buf, 256);
                write(sockfd, buf, nbytes);
            }
        }
    }

}
