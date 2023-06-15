#include<stdio.h>
#include<sched.h>
#include<unistd.h>
int main()
{
	int scheduler;
	scheduler = sched_getscheduler(getpid());

	printf("the scheduler policy of the current process is: %d\n",scheduler);
	printf("the max priority value for SCHED_OTHER is %d\n",sched_get_priority_max(SCHED_OTHER));
	printf("the min priority value for SCHED_OTHER is %d\n",sched_get_priority_min(SCHED_OTHER));
	printf("the max priority value for SCHED_FIFO is %d\n",sched_get_priority_max(SCHED_FIFO));
	printf("the min priority value for SCHED_FIFO is %d\n",sched_get_priority_min(SCHED_FIFO));
	printf("the max priority value for SCHED_RR is %d\n",sched_get_priority_max(SCHED_RR));
	printf("the min priority value for SCHED_RR is %d\n",sched_get_priority_min(SCHED_RR));
}

