#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>

int main()
{
	int fd;
	char Ubuff[]="Thios is buffer";
	char Kbuff[100];
	fd=open("dev/MyCharDevice",O_RDWR,0777);
	if(fd<0)
	{
		printf(" Error opening driver\n");
		exit(1);
	}
	write(fd,Ubuff,sizeof(Ubuff));
	read(fd,Kbuff,50);
	printf("The data read fron kernel is %s\n",Kbuff);
	close(fd);
}
