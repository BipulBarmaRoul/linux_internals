#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void hello(void);
int main()
{
	        //signal(SIGALRM, hello);
		printf("my pid is: %d\n",getpid());
		//signal(SIGALRM, SIG_DFL);
		signal(SIGALRM, SIG_IGN);
		//alarm(2);
		while(1);
}

void hello()
{
		printf("hello world\n");
                alarm(2);
}

