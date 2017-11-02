/* thr1cond.c  */
//demo use of condition variable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
//condition variable need a mutex
pthread_cond_t cond =  PTHREAD_COND_INITIALIZER;
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

char buf[32];

void *thrfun(void *data)
{
	int id = *(int *)data;

	while ( 1 ) {
	    pthread_mutex_lock(&mut);//obtain the lock to wait
		pthread_cond_wait(&cond,&mut);
		int val = atoi(buf);
        pthread_mutex_unlock(&mut);
		printf("Thread %d worked, answer = %d\n",id,val*2);
	}
}

int main(int argc, char *argv []) 
{

	pthread_t th1,th2;
	int id1=1,id2=2;

	if (pthread_create(&th1,NULL,thrfun,&id1) ) {
		fprintf(stderr,"fail to create thread!\n");
		exit(1);
	}
	if (pthread_create(&th2,NULL,thrfun,&id2) ) {
		fprintf(stderr,"fail to create thread!\n");
		exit(1);
	}
	printf("Please enter a number for calculation :");
    char inbuf[64];
	while ( 1 ) {
		fgets(inbuf,64,stdin);
		pthread_mutex_lock(&mut);
        strncpy(buf,inbuf,64);
		pthread_mutex_unlock(&mut);
		pthread_cond_signal(&cond);
	}
}
