#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<signal.h>
#include<stdlib.h>
void handler1();
void handler2();
int main()
{
	printf("my pid is:%d\n",getpid());
	signal(SIGHUP,handler1);
	signal(SIGKILL,handler2);
	getchar();
	while(1)
	{
		printf("i am from phytec\n");
	}
}

void handler1()
{
	printf("hello handler1\n");
}
void handler2()
{
	printf("hello handler2\n");
}

