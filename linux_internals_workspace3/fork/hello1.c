#include<stdio.h>
#include <unistd.h>
int main()
{
	char *fp = "ls";
	char *arg1 = "-a";
	char *arg2 = "-s";
	//char *args[] = {"./hello2,NULL};
	printf("hello iam bipul, my id is:%d\n",getpid());
	//execv(args[0],args);
	//execle(args[0],args);
	execlp(fp,arg1,arg2);
	printf("hello i am hello-1\n");
}


