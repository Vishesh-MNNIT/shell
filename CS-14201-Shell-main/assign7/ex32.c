#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = {"./chld.sh", "./prnt.sh", NULL};

    if (fork() == 0)
        execvp(args[0], args);
    else {
        execvp(args[1], args);
        wait(NULL);
        printf("child has terminated\n");
    }

    printf("Bye\n");
    return 0;
}

