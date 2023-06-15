#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

static int global = 0;
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
static void *thread1(void *arg)
{
	int local = 1000000;
	int loc, i;
	pthread_mutex_lock(&mut);
	for(i=0;i<local;i++)
	{
		loc = global;
		loc++;
		global = loc;
	}
	pthread_mutex_unlock(&mut);
	printf("value from thread 1\n");
	printf("loc value is %d\n",loc);
	return NULL;
}

static void *thread2(void *arg)
{
        int local = 1000000;
        int loc, j;
	pthread_mutex_lock(&mut);
        for(j=0;j<local;j++)
        {
                loc = global;
                loc++;
                global = loc;
        }
	pthread_mutex_unlock(&mut);
	printf("value from thread 2\n");
	printf("loc value is %d\n",loc);
        return NULL;
}


int main()
{
	int local;
	pthread_t t1;
	pthread_t t2;
	int s;
	s = pthread_create(&t1, NULL, thread1, NULL);
	if(s!=0)
        {
                perror("thread create\n");
        }
	s = pthread_create(&t2, NULL, thread2, NULL);
	if(s!=0)
	{
		perror("thread create\n");
	}

	s = pthread_join(t1, NULL);
	if(s!=0)
        {
                perror("thread create join\n");
        }

	s = pthread_join(t2, NULL);
        if(s!=0)
        {
                perror("thread create join\n");
        }

	printf("global variable is %d\n",global);
	exit(0);
}
