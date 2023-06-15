#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

static void *threadFunc(void *arg)
{

        printf("Thread: threadFunc started\n");
	pthread_detach(pthread_self());
	while(1)
	{
		sleep(1);
                printf("threadfunc: executing loop\n");
	}
	printf("threadFunc:exiting now\n");
}

int main(int argc, char *argv[])
{
	int count;
        pthread_t t1;
        int s;
	printf("main thread started\n");
        s = pthread_create(&t1, NULL, threadFunc, NULL);
        if(s!=0)
        {
                perror("thread create error\n");
        }
	for(count = 0; count < 10; count++)
	{
		sleep(2);
		printf("\nmain thread: count value = %d\n",count);
	}
	pthread_cancel(t1);
        printf("\nmain thread: exiting now\n");
        pthread_exit(NULL);
}

