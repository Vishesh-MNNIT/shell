#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <stdlib.h> 
int main()
{
int pfds[2];
char buf[30];
if(pipe(pfds)==-1)
{
perror("pipe failed");
exit(1);
}
if(!fork())
{
close(1);
dup(pfds[1];
system (“ls –l”);
}
else
{
printf("parent reading from pipe \n");
while(read(pfds[0],buf,80))
printf("%s \n" ,buf);
}
}


/*
[student@gcet ~]$ vi pipes2.c
[student@gcet ~]$ cc pipes2.c
[student@gcet ~]$ ./a.out
Parent reading from pipe
Total 24
-rwxrwxr-x l student student 5563Aug 3 10:39 a.out
-rw-rw-r—l
Student student 340 jul 27 10:45 pipe2.c
-rw-rw-r—l student student
Pipes2.c
-rw-rw-r—l student student 401 34127 10:27 pipe2.c
student
*/


// chat gpt
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    int pipefd[2];
    pid_t pid1, pid2;

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid1 = fork();

    if (pid1 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid1 == 0) {
        // Child process 1
        close(pipefd[0]); // Close read end of the pipe

        // Redirect stdout to the write end of the pipe
        if (dup2(pipefd[1], STDOUT_FILENO) == -1) {
            perror("dup2");
            exit(EXIT_FAILURE);
        }

        execlp("ls", "ls", "-l", NULL); // Execute first command
        exit(EXIT_FAILURE); // If exec fails
    }

    pid2 = fork();

    if (pid2 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid2 == 0) {
        // Child process 2
        close(pipefd[1]); // Close write end of the pipe

        // Redirect stdin to the read end of the pipe
        if (dup2(pipefd[0], STDIN_FILENO) == -1) {
            perror("dup2");
            exit(EXIT_FAILURE);
        }

        execlp("grep", "grep", "file", NULL); // Execute second command
        exit(EXIT_FAILURE); // If exec fails
    }

    // Parent process
    close(pipefd[0]); // Close both ends of the pipe
    close(pipefd[1]);

    // Wait for child processes to finish
    wait(NULL);
    wait(NULL);

    return 0;
}








#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int fd[2];
    if (pipe(fd) == -1) return 1;

    int pid1 = fork();
    if (pid1 < 0)return 2;
    if (pid1 == 0) {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
//        execlp("ping", "ping", "-c", "5", "google.com", NULL);
        execlp("cat", "cat", argv[1], NULL);
    }

    int pid2 = fork();
    if (pid2 < 0)return 3;
    if (pid2 == 0) {
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
//        execlp("grep", "grep", "rtt", NULL);
        execlp("grep", "grep", argv[2], NULL);
    }

    close(fd[0]);
    close(fd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    return 0;
}