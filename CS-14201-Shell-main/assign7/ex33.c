#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char **argv) {
    char *command = strtok(argv[1], ";");

    while (command != NULL) {
        system(command);
        command = strtok(NULL, ";");
    }

    return 0;
}
