#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    pid_t pid;
    int status;
    pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        execvp(argv[1], &argv[1]);
        perror("execvp");
        exit(1);
    } else {
        alarm(5);
        waitpid(pid, &status, 0);
        alarm(0);
        if (WIFSIGNALED(status) && WTERMSIG(status) == SIGALRM) {
            printf("Command timed out after 5 seconds, killing process %d\n", pid);
            kill(pid, SIGKILL);
        }
    }
    return 0;
}
