/* thr_spinlock.c  */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_spinlock_t spinlock0;
int common_val = 0;

void *myfunc(void *data)
{
    int n;
    for ( n = 0; n < 1000000; n++ ) {
        pthread_spin_lock(&spinlock0);
        common_val = common_val + 1;
        pthread_spin_unlock(&spinlock0);
    }
}

int main(int argc, char *argv []) 
{
    int n;
    pthread_t th1, th2;
    int id1 = 1, id2 = 2;
    pthread_spin_init(&spinlock0, PTHREAD_PROCESS_PRIVATE);

    pthread_create(&th1, NULL, myfunc, &id1);
    pthread_create(&th2, NULL, myfunc, &id2);
    
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    printf("All threads joined, common_val = %d\n", common_val);
}
