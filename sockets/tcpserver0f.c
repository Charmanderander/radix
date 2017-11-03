/* tcpserver0f.c  */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>

#define MYPORT 45000

#define errquit(msg) { perror(msg); exit(EXIT_FAILURE); }
void child_handler(int signum) 
{
    int status;
    pid_t pid = waitpid(-1, &status, WNOHANG);
    if ( pid > 0 ) 
       printf("process %d had ended!\n", pid);
}
void install_handler() 
{
    struct sigaction act;
    act.sa_handler = child_handler;
    act.sa_flags = SA_RESTART;
    sigemptyset(&act.sa_mask);

    if ( sigaction(SIGCHLD, &act, NULL) == -1 ) 
        errquit("SIGCHLD");
}

int main(int argc, char *argv []) 
{
    install_handler();

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
    int confd;
    while ( 1 ) {
        printf("waiting for connection\n");
        confd = accept(sockfd, (struct sockaddr*) &peeraddr, &peerlen);
        printf("Received connection from: %s:%d\n", inet_ntoa(peeraddr.sin_addr), 
                ntohs(peeraddr.sin_port));
        pid_t pid = fork();
        if ( pid == 0 ) break;
        close(confd);
    }
    int n = 0, nbytes;
    char buf[256];
    while ( n++ < 30) {
        nbytes = snprintf(buf, 256, "Welcome to Server, n = %d\n", n);
        if ( write(confd, buf, nbytes) == -1 ) errquit("write");
        sleep(1);
    }

}
