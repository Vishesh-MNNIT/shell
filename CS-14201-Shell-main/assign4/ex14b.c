#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int readFile(char *filename) {
    char str;
    int c = 0;
    //opens the file using the open function, 
    //which returns a file descriptor fd that represents the file.
    int fd = open(filename, O_RDONLY);

    if (fd) {
        //The if statement checks if fd is a valid file descriptor. 
        //If it is, the while loop reads each character from the file using the read function
        // until the end of file is reached (read returns 0).
        while (read(fd, &str, 1) == 1) {
            if (str == ' ')
                ++c;
        }
    } else printf("File not found!");

    close(fd);
    return c;
}

int main(int argc, char **argv) {
    printf("Spaces = %d\n", readFile(argv[1]));
    return 0;
}
