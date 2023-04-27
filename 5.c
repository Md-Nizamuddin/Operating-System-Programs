//Q. Sum of Odd & Even numbers - 2 different processes

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
    int pid1, pid2, sumodd=0, sums=0, sumn=0, sumeven=0, n, i;
    printf("Enter the value of n : ");
    scanf("%d", &n);
    pid1=fork();
    pid2=fork();
    if(pid1==0)
    {
        if(pid2==0)
        {
            for(i=0;i<=n;i++)
            {
                sumn+=i;
            }
        printf("\nSum of %d numbers is %d \n",n,sumn);
        }
        else
        {
            wait(NULL);
            for(i=0; i<=n; i++)
            {
                sums+=i*i;
            }
            printf("\nSum of squares of numbers is %d \n",sums);
        }
    }
    else
    {
        wait(NULL);
        if(pid2==0)
        {
            for(i=0;i<=n;i++)
            {
                if(i%2!=0)
                {
                    sumodd+=i;
                }
            }
            printf("\nSum of Odd Numbers is %d \n", sumodd);
        }
        else
        {
            for(i=0; i<=n; i++)
            {
                if(i%2==0)
                {
                    sumeven+=i;
                }
            }
            printf("\nSum of Even numbers is %d \n", sumeven);
        }
    }
return 0;
}


// --output--

// Enter the value of n : 5
// Sum of Odd Numbers is 9 
// Sum of 5 numbers is 15 
// Sum of Even numbers is 6 
// Sum of squares of numbers is 55