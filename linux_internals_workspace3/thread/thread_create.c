#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

static void *threadFunc(void *arg)
{
	char *str = (char *) arg;
	printf("ThreadFunc: arguments passed to thread are: %s,pid = %d\n",str, getpid());
	(void) sleep(15);
	printf("threadfunc: exiting Now\n");
	return 0;
	pthread_exit(0);
}

int main(int argc, char *argv[])
{
	pthread_t t1;
	void *res;
	int s;
	s = pthread_create(&t1, NULL, threadFunc, "HELLO world");
	if(s!=0)
	{
		perror("thread create error\n");
	}
	printf("main thread : message from main(), pid = %d\n",	getpid());
	sleep(5);
	printf("\nmain thread: exiting now\n");
	pthread_exit(0);
//	exit(0);
}

