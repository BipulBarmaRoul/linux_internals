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
        int fd1 = open("f1",O_RDONLY);
        int fd2 = open("f2",O_WRONLY);
        while(1)
        {
                read(fd1,ch1,sizeof(ch1));
                printf("Received Message:%s\n",ch1);
		printf("Enter the message to send....\n");
		scanf("%s", ch2);
                write(fd2, ch2, strlen(ch2) + 1);
		sleep(1);
        }
	return 0;
}
 
