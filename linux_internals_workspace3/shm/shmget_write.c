#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define KEY 1234
int main()
{
	int ret;
	char *mat;
	ret = shmget(KEY, 8000, IPC_CREAT|0666);
	printf("%d is the return address of shared memory\n",ret);
	mat = shmat(ret, (const void *)0, 0);
	strcpy((char *)mat,"hello");
	if(shmget > 0)
	{
		printf("shared memory segment created successfully\n");
	}
}

