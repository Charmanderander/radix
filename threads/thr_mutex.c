/* thr_mutex.c  */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex0 = PTHREAD_MUTEX_INITIALIZER;
int common_val = 0;

void *myfunc(void *data)
{
    int n;
    for ( n = 0; n < 1000000; n++ ) {
        pthread_mutex_lock(&mutex0);
        common_val = common_val + 1;
        pthread_mutex_unlock(&mutex0);
    }
}

int main(int argc, char *argv []) 
{
    int n;
    pthread_t th1, th2;
    int id1 = 1, id2 = 2;

    pthread_create(&th1, NULL, myfunc, &id1);
    pthread_create(&th2, NULL, myfunc, &id2);
    
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    printf("All threads joined, common_val = %d\n", common_val);
}
