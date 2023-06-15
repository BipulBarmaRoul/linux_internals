#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<signal.h>

#define CHILD 0
void handler(void);
int main()
{
	pid_t cpid;
        cpid = fork();
	if(cpid < CHILD)
	{
		printf("failed to create a child\n");
	}
	else if(cpid == CHILD)
	{
		printf("i am in child process, my pid is:%d\n",getpid());
		sleep(2);

	}
	else
	{
		signal(SIGCHLD,handler);
		while(1)
		{
			printf("i am in parent process\n");
			sleep(1);
		}
	}
}

void handler()
{
	printf("i am in handler\n");
	wait(NULL);
}

