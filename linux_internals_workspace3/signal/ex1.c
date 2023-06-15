#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void hello(int sig)
{
	printf("I got a signal: %d\n",sig);
	//(void) signal(SIGINT, SIG_DFL);
}

int main()
{
	printf("my process is %d\n",getpid());
	(void) signal(SIGINT, hello);
	while(1)
	{
		//(void) signal(SIGINT, SIG_IGN);
		(void) signal(SIGTERM, hello);
		printf("hello world\n");
		sleep(1);
	}
	return 0;
}

