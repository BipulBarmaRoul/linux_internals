#include<stdio.h>
int main()
{
	int pid;
	//printf("before fork pid is: %d\n",getpid());
	pid = fork();
	/*if((pid = fork())==0)
	{
		printf("hello child\n");
	}
	else
	{
		printf("hello parent\n");
	}*/
	if(pid > 0)
        {
                printf("hello parent\n");
        }
        else
        {
                printf("hello child\n");
        }

	//printf(" %d pid\n",pid);
	//printf("after fork pid is: %d\n",getpid());
	getchar();
}

