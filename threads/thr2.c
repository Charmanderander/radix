/* thr1.c  */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *myfunc(void *data)
{
    int n, *nptr;

    int id = *(int *)data;
    
    for ( n = 0; n < 5; n++ ) {
        printf("Thread #%d: n = %d\n",id, n);
        sleep(1);
    }
    nptr = malloc(sizeof(int));
    *nptr = n;
    return nptr;
}
int main(int argc, char *argv []) 
{
    int n;
    pthread_t th1, th2;
    int id1 = 1, id2 = 2;

    pthread_create(&th1, NULL, myfunc, &id1);
    pthread_create(&th2, NULL, myfunc, &id2);
    
    int *resptr;

    pthread_join(th1, (void **)(&resptr));
    printf("thread1 joined, result = %d\n", *resptr);
    free(resptr);
    pthread_join(th2, (void **)(&resptr));
    printf("thread2 joined, result = %d\n", *resptr);
    free(resptr);
}
