#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>

int main()
{
	int fd,result;
	char buff[100]="This is device 2 and thi stext should exceed 50 bytes";
	fd=open("/dev/dev2",O_RDWR,0777);
	if(fd<0)
	{
		printf("\nzError opening driver");
		exit(1);
	}
	write(fd,buff,sizeof(buff));
	wait_event(w_queue,condition);
	read(fd,&buff,sizeof(char*));
	close(fd);
}

