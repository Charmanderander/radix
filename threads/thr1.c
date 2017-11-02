/* thr1.c  */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *myfunc(void *data)
{
    int n;
    for ( n = 0; n < 30; n++ ) {
        printf("Thread, n = %d\n", n);
        sleep(1);
    }
}
int main(int argc, char *argv []) 
{
    pthread_t th;
    pthread_create(&th, NULL, myfunc, NULL);


}
