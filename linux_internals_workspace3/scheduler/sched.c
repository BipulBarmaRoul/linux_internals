#include<stdio.h>
#include<sched.h>
#include<unistd.h>
int main()
{
	int policy;
	policy = sched_getscheduler(90);
	switch(policy)
	{
		case SCHED_OTHER:
			printf("%s current policy in force: SCHED_OTHER\n",__func__);
			break;
		case SCHED_RR:
                        printf("%s current policy in force: SCHED_RR\n",__func__);
                        break;
		case SCHED_FIFO:
                        printf("%s current policy in force: SCHED_FIFO\n",__func__);
                        break;
	}
	return 0;
}

