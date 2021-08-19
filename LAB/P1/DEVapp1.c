#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>

int main()
{
	int fd,result;
	char buff[100]="This is device 1 and the text should be more than 50  bytes";
	fd=open("/dev/dev2",O_RDWR,0777);
	if(fd<0)
	{
		printf("Error opening Device 1");
		exit(1);
	}
	 write(fd,buff,sizeof(buff));
	 wait_event(w_queue,conditi0on); //include semaphore and use as condition
	 read(fd,&buff,sizeof(char));
	 close(fd);
}
