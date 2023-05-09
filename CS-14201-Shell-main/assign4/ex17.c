#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void print_file_info(char *filename) {
    struct stat file_info;

    if (stat(filename, &file_info) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    printf("File type: ");
    switch (file_info.st_mode & S_IFMT) {
        case S_IFBLK:  printf("block device\n");            break;
        case S_IFCHR:  printf("character device\n");        break;
        case S_IFDIR:  printf("directory\n");               break;
        case S_IFIFO:  printf("FIFO/pipe\n");               break;
        case S_IFLNK:  printf("symlink\n");                 break;
        case S_IFREG:  printf("regular file\n");            break;
        case S_IFSOCK: printf("socket\n");                  break;
        default:       printf("unknown?\n");                break;
    }

    printf("Number of links: %ld\n", (long) file_info.st_nlink);

    printf("Time of last access: %s", ctime(&file_info.st_atime));

    printf("Permissions: ");
    printf( (S_ISDIR(file_info.st_mode)) ? "d" : "-");
    printf( (file_info.st_mode & S_IRUSR) ? "r" : "-");
    printf( (file_info.st_mode & S_IWUSR) ? "w" : "-");
    printf( (file_info.st_mode & S_IXUSR) ? "x" : "-");
    printf( (file_info.st_mode & S_IRGRP) ? "r" : "-");
    printf( (file_info.st_mode & S_IWGRP) ? "w" : "-");
    printf( (file_info.st_mode & S_IXGRP) ? "x" : "-");
    printf( (file_info.st_mode & S_IROTH) ? "r" : "-");
    printf( (file_info.st_mode & S_IWOTH) ? "w" : "-");
    printf( (file_info.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s file1 [file2 ...]\n", argv[0]);
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {
        printf("File: %s\n", argv[i]);
        print_file_info(argv[i]);
        printf("\n");
    }

    return EXIT_SUCCESS;
}




/*
#include <sys/types.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <utime.h>
#include <fcntl.h>

void print_perms(mode_t perms)
{
    printf( (perms & S_IRUSR) ? "r" : "-");
    printf( (perms & S_IWUSR) ? "w" : "-");
    printf( (perms & S_IXUSR) ? "x" : "-");
    printf( (perms & S_IRGRP) ? "r" : "-");
    printf( (perms & S_IWGRP) ? "w" : "-");
    printf( (perms & S_IXGRP) ? "x" : "-");
    printf( (perms & S_IROTH) ? "r" : "-");
    printf( (perms & S_IWOTH) ? "w" : "-");
    printf( (perms & S_IXOTH) ? "x" : "-");
    printf("\n");
}

int main(int argc, char** argv)
{
    struct dirent *myFile;
    struct stat info;
    stat(argv[1], &info);
    DIR *dir = opendir(argv[1]);

    if(dir)
    {
        while ((myFile = readdir(dir))) {
            printf("%s\n", myFile->d_name);
            printf("Type : ");
            print_perms(info.st_mode);
            printf("Links : %4d\n", info.st_nlink);
            printf("Last access : %s\n", ctime(&info.st_atimespec));
        }
    }
    closedir(dir);
    return 0;
}

*/

/*
clear
for i in $*
do
if [ -d $i ]
then
echo “Given directory name is found as $i”
fi
if [ -f $i ]
then
echo “Given name is a file as $i “
fi
echo “Type of file/directory $i”
file $i
echo “Last access time is:”
ls -l$i | cut-c 31-46
echo  "no.of links"
ln $i
if [ -x $i –a -w $i-a –r $i ]
then
echo “$i contains all permission”
else
echo “$i does not contain all permissions”
fi
done
*/
