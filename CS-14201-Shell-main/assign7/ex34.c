#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd[2];
    pid_t pid;

    if (argc < 3) {
        printf("Usage: %s <command1> <command2>\n", argv[0]);
        return 1;
    }

    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        execlp(argv[1], argv[1], NULL);
        perror("execlp");
        exit(1);
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        execlp(argv[2], argv[2], NULL);
        perror("execlp");
        exit(1);
    }

    close(fd[0]);
    close(fd[1]);
    waitpid(-1, NULL, 0);
    waitpid(-1, NULL, 0);
    return 0;
}
