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

typedef struct msgbuf
{
        long mtype;
        char buffer[100];
}msg;
int main()
{
        msg m1;
        int i,qid;
        qid = msgget(KEY,IPC_CREAT);
        m1.mtype = 1;
	i = msgrcv(qid,&m1,sizeof(msg),1,0);
        for (i=0;i<100;i++)
        {
                printf("%c\n",m1.buffer[i]);
        }
        printf("%d\n",qid);
        printf("return value of msgsnd is:%d\n",i);

}

