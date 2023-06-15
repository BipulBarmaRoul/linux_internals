#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 100
static void *threadFunc(void *arg)
{
        //char *str = (char *) arg;
	int count = 0;
        printf("Thread: threadFunc started\n");
	for(count = 0; count < MAX; count++);
        sleep(5);
        printf("threadfunc: exiting Now\n");
	if(count < 500)
	{
		return (void *) " count < 500";
	}
	else
	{
		return (void *) " count > 500";
	}
        
}

int main(int argc, char *argv[])
{
        pthread_t t1;
        void *res;
        int s;
        s = pthread_create(&t1, NULL, threadFunc, NULL);
        if(s!=0)
        {
                perror("thread create error\n");
        }
        //#if 0
	    s = pthread_join(t1, &res);
	    if(s!=0)
            {
                    perror("thread create error\n");
          {
        //char *str = (char *) arg;
        int count = 0;
        printf("Thread: threadFunc started\n");
        for(count = 0; count < MAX; count++);
        sleep(5);
        printf("threadfunc: exiting Now\n");
        if(count < 500)
        {
                return (void *) " count < 500";
        }
        else
        {
                return (void *) " count > 500";
        }

}

int main(int argc, char *argv[])
{
        pthread_t t1;
        void *res;
        int s;
        s = pthread_create(&t1, NULL, threadFunc, NULL);
        if(s!=0)
        {
                perror("thread create error\n");
        }
        //#if 0
            s = pthread_join(t1, &res);
            if(s!=0)
            {
                    perror("thread create error\n");
            }
            printf("main thread : thread returned %s\n", (char *)res);
        //#endif
        printf("\nmain thread: exiting now\n");
        pthread_exit(NULL);
}
  }
            printf("main thread : thread returned %s\n", (char *)res);
        //#endif
        printf("\nmain thread: exiting now\n");
        pthread_exit(NULL);
}

