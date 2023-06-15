#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
//int val;
int main()
{
	//int child_state;
	//val = 5;
	pid_t fork_val = fork();
	int fds[2];
	char buf[20];
	pipe(fds);
	if(fork_val < 0)
	{
		printf("failed to create a child\n");
	}
	else if(fork_val == 0)
	{
		printf("i am in child process, my pid is:%d\n",getpid());
		read(fds[0],buf,15);
                printf("%s\n",buf);
		//char *args[] = {"./hello2",NULL};
		//execv(args[0],args);
		//val = 10;
		//printf("value is:%d\n",val);
//		sleep(10);
	}
	else
	{
		//wait(&child_state);
		printf("i am in parent process, my pid is:%d\n",getpid());
		write(fds[1],"hello world\n",11);
		//printf("value is:%d\n",val);
//		sleep(15);
	}
}
