#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	char ch1[20];
	char ch2[20];
        mkfifo("f1",0666);
        mkfifo("f2",0666);
	int fd1 = open("f1",O_WRONLY);
	int fd2 = open("f2",O_RDONLY);
	while(1)
	{
		printf("Enter the message to send....\n");
		scanf("%s",ch1);
		write(fd1,ch1,strlen(ch1)+1);
		read(fd2,ch2,sizeof(ch2));
		printf("Received Message:%s\n",ch2);
		sleep(1);
	}
}


