/* chatserver0.c  */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/poll.h>

#define MYPORT 45000

#define errquit(msg) { perror(msg); exit(EXIT_FAILURE); }

int main(int argc, char *argv []) 
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if ( sockfd == -1 ) errquit("socket");
    int sockopt = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &sockopt, sizeof sockopt );//reuser addr

    struct sockaddr_in myaddr, peeraddr;
    socklen_t peerlen = sizeof(peeraddr);

    myaddr.sin_family = AF_INET;
    myaddr.sin_port   = htons(MYPORT);
    myaddr.sin_addr.s_addr = INADDR_ANY;
    if ( bind(sockfd, (struct sockaddr *)&myaddr, sizeof(myaddr)) == -1 ) 
        errquit("bind");

    if ( listen(sockfd, 3) == -1 ) errquit("listen");
    printf("waiting for connection\n");
    int confd = accept(sockfd, (struct sockaddr*) &peeraddr, &peerlen);
    printf("Received connection from: %s:%d\n", inet_ntoa(peeraddr.sin_addr), 
                                                ntohs(peeraddr.sin_port));
    int n = 0, nbytes;
    char buf[256];
    nbytes = snprintf(buf, 256, "Welcome to Server, n = %d\n", n);
    if ( write(confd, buf, nbytes) == -1 ) errquit("write");
    
    struct pollfd myfds[2];

    myfds[0].fd = 0;
    myfds[0].events = POLLIN;
    myfds[1].fd = confd;
    myfds[1].events = POLLIN;
    
    while ( n++ < 30) {
        int res = poll(myfds, 2, -1);
        if ( res == -1 ) errquit("poll");

        if ( res > 0 ) {
            if ( myfds[1].revents & POLLIN ) {
                nbytes = read(confd, buf, 256);
                if (nbytes == 0 || nbytes == -1 ) break;
                write(1, buf, nbytes);
            }
            if ( myfds[0].revents & POLLIN ) {
                nbytes = read(0, buf, 256);
                write(confd, buf, nbytes);
            }
        }
    }



}
