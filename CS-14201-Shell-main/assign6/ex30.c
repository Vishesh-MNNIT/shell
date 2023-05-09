#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct stat st;
    if (stat(argv[1], &st) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    uid_t uid = getuid();
    gid_t gid = getgid();

    printf("File access rights for %s:\n", argv[1]);
    printf("Owner: %s\n", st.st_uid == uid ? "rw" : (st.st_mode & S_IRUSR ? "r" : "-"));
    printf("Group: %s\n", st.st_gid == gid ? "rw" : (st.st_mode & S_IRGRP ? "r" : "-"));
    printf("Others: %s\n", st.st_mode & S_IROTH ? "r" : "-");

    return 0;
}
