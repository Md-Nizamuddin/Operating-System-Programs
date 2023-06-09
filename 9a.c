// C Program for Shared Memory  (Writer Process)

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
    shmid=shmget((key_t)2345, 1024, 0666|IPC_CREAT);   
    shared_memory=shmat(shmid,NULL,0);   
    
    printf("Enter Data \n");  
    read(0,buff,100);
    strcpy(shared_memory,buff);
    printf("You wrote : %s\n",(char *)shared_memory);  

return 0;
}

// --output--

// Key of shared memory is 65581
// Process attached at 0x7fc2737d3000
// Enter some data to write to shared memory
// congratulaations
// You wrote : congratulaations
