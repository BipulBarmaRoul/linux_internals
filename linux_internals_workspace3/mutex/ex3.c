#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int doneFlag = 0;
char buf[100];
void *thread1(void *p)
{
	printf("Thread 1 scheduled first\n");
	sleep(1);
	pthread_mutex_lock(&mut);
	printf("\nthread 1: critical section executes always first\n");
	sprintf(buf,"This is data buffer");
	doneFlag = 1;
	pthread_cond_signal(&cond);
	pthread_mutex_unlock(&mut);
}

void *thread2(void *p)
{
	printf("Thread 2 scheduled second\n");
        sleep(1);
        pthread_mutex_lock(&mut);
	if(doneFlag == 0)
	{
		pthread_cond_wait(&cond, &mut);
	}
        printf("\nthread 2: signal received from thread 1, this is always executed after thread 1 critical section %d\n",doneFlag);
        printf("\nThe buffer received from producer thread is : %s\n",buf);
        pthread_mutex_unlock(&mut);
}


int main()
{
	//srand(time(0));
	pthread_t t1;
	pthread_t t2;
	pthread_create(&t1, NULL, thread1, NULL);
	pthread_create(&t2, NULL, thread2, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	printf("main thread is exiting now\n");
	return (EXIT_SUCCESS);
}
