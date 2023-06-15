#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

static void *threadFunc(void *arg)
{

        printf("Thread: threadFunc started\n");
	pthread_detach(pthread_self());
        sleep(5);
        printf("threadfunc: exiting Now\n");
}

int main(int argc, char *argv[])
{
        pthread_t t1;
        int s;
        s = pthread_create(&t1, NULL, threadFunc, NULL);
        if(s!=0)
        {
                perror("thread create error\n");
        }
        printf("\nmain thread: exiting now\n");
        pthread_exit(NULL);
}

