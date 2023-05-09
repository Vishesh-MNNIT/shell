#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <utime.h>

int main(int argc, char *argv[]) {
    struct stat statbuf;
    struct utimbuf utimes;

    if (stat(argv[2], &statbuf) == -1) {
        perror("stat");
        return 1;
    }

    utimes.actime = statbuf.st_atime;
    utimes.modtime = statbuf.st_mtime;
    if (utime(argv[1], &utimes) == -1) {
        perror("utime");
        return 1;
    }

    printf("Timestamps of %s set to those of %s\n", argv[1], argv[2]);

    return 0;
}
