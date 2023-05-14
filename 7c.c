//Q. Named Pipe

#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
    char buff[25];
    int rfd,wfd;
    mkfifo("fifo",O_CREAT|0644);
    if (fork()==0)
    {
        printf("Child writing into FIFO\n");
        wfd=open("fifo",O_WRONLY);
        write(wfd,"Hello",6);
    }
    else
    {
        rfd=open("fifo",O_RDONLY);
        read(rfd,buff,6);
        printf("Parent reads from FIFO : %s\n",buff);
    }
return 0;
} 

// --output--

// Child writing into FIFO
// Parent reads from FIFO : Hello


