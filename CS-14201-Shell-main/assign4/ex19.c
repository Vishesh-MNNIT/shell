#include<stdio.h>
#include<unistd.h>
int main()
{
    pid_t p;
    
    printf("pid of main program:\t%d\n", getpid());
    p = fork();
    
     if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(-1);
    }

    else if(p == 0)
    {
        printf("In child process,\tpid:\t%d,\tppid:\t%d\n", getpid(), getppid());
    }
    else
    {
        printf("In parent,\t\tpid:\t%d,\tfork returned:\t%d\n", getpid(), p);
    }
}




