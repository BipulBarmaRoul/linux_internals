#include <fcntl.h>          
#include <sys/stat.h>        
#include <semaphore.h>
#include <stdio.h>

int main()
{
	unsigned int value;
	int sval;
	sem_t *sem;
	sem = sem_open("/sem1",O_CREAT | O_RDWR, 0660,1);
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
	sem_wait(sem);
	sem_getvalue(sem, &sval);
	printf("after sem_wait semaphore value = %d\n",sval);
	printf("process 1: executing critical section\n");
	sleep(10);
	sem_post(sem);
	printf("\ncritical section executed\n");
	sem_getvalue(sem, &sval);
	printf("after sem_post semaphore value = %d\n",sval);
	sem_unlink("/sem1");
}

	
