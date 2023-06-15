#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define KEY 1234
int main()
{
	struct shmid_ds buf;
	int ret;
	void *mem;
	ret=shmget(KEY,8000,IPC_CREAT|0666);
	printf("%d is the return address of the memory\n");
        mem=shmat(ret,(const *)0,0);
	shmctl(ret,SHM_STAT,&buf);
//	buf.shm_perm=0666;
	printf("Last attach time is %d\n",buf.shm_atime);
	printf("Last detach time is %d\n",buf.shm_dtime);
	printf("No. of current attaches is  %d\n",buf.shm_nattch);

}

