/* fork0.c  */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv []) 
{
    pid_t child1, child2;
    int n = 0;
    int j = 0;
    int k = 0;
    int status;
    child1 = fork();

    if ( child1 == 0 ) {
        while ( n++ < 10) {
            printf("1\n");
            sleep(1);
        }
    } else {
        child2 = fork();
        if ( child2 == 0 ) {
            while ( j++ < 10) {
                printf("2\n");
                sleep(1);
            }  
        } else {
              while ( k++ < 20 ){
                  printf("P\n");
                  sleep(1);
              }
          }
      }  
	return 0;
}
