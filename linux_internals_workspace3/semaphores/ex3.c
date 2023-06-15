#include <fcntl.h>           
#include <sys/stat.h>        
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
	int sval,ret;
	sem_t *sem;
	sem = sem_open("/sem1",O_RDWR);
	if(sem == SEM_FAILED)
	{
		perror("sem open fail\n");
		return -1;
	}
	else
	{
		printf("sem open successfully\n");
	}
	sem_getvalue(sem, &sval);
	printf("before sem_wait semaphore value = %d\n",sval);
	ret = sem_wait(sem);
	printf("process 2: executing critical section\n");
	sleep(10);
	printf("\nret is :%d\n",ret);
	printf("\nprocess 2:\n");
	sem_post(sem);
	printf("after sem_post semaphore value = %d\n",sval);
	printf("\nprocess:2 executed critical section\n");
	return 0;
}

	
