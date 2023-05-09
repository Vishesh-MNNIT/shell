#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

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

    printf("File permissions for %s:\n", argv[1]);
    printf("Owner: read = %c, write = %c, execute = %c\n", st.st_mode & S_IRUSR ? 'r' : '-', st.st_mode & S_IWUSR ? 'w' : '-', st.st_mode & S_IXUSR ? 'x' : '-');
    printf("Group: read = %c, write = %c, execute = %c\n", st.st_mode & S_IRGRP ? 'r' : '-', st.st_mode & S_IWGRP ? 'w' : '-', st.st_mode & S_IXGRP ? 'x' : '-');
    printf("Others: read = %c, write = %c, execute = %c\n", st.st_mode & S_IROTH ? 'r' : '-', st.st_mode & S_IWOTH ? 'w' : '-', st.st_mode & S_IXOTH ? 'x' : '-');

    return 0;
}
