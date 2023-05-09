#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 512

int main(int argc, char *argv[])
{
    int src_fd, dest_fd, n;
    char buf[BUFSIZE];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source file> <destination file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    src_fd = open(argv[1], O_RDONLY);
    if (src_fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    while ((n = read(src_fd, buf, BUFSIZE)) > 0) {
        if (write(dest_fd, buf, n) != n) {
            perror("write");
            exit(EXIT_FAILURE);
        }
    }

    if (n == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    if (close(src_fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }

    if (close(dest_fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }

    return 0;
}
