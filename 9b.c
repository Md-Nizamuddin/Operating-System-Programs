// C Program for Message Queue (Reader Process)

#include<stdio.h>  
#include<stdlib.h>  
#include<unistd.h>  
#include<sys/shm.h>  
#include<string.h>

int main()  
{  
    int i;  
    void *shared_memory;  
    char buff[100];  
    int shmid;  
    shmid=shmget((key_t)2345, 1024, 0666);  
    printf("Key of shared memory is %d\n",shmid);  
    shared_memory=shmat(shmid,NULL,0);
    printf("Process attached at %p\n",shared_memory);  
    printf("Data read from shared memory is : %s\n",(char *)shared_memory);  

return 0;
}  

// --output--

// Key of shared memory is 65581
// Process attached at 0x7f5b1382b000
// Data read from shared memory is : congratulaations