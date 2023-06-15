#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define KEY 1234


int main()
{
	struct msqid_ds buf;
	int qid;
        qid = msgget(KEY,IPC_CREAT);
	msgctl(qid,IPC_STAT,&buf);
	printf("number of message in queue is:%d\n",buf.msg_qnum);
	printf("maximum number of byte in queue is:%d\n",buf.msg_qbytes);
	printf("Current number of bytes in queue is:%d\n",buf.__msg_cbytes);

}
