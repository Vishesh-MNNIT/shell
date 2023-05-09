// ls UNIX

#include <sys/types.h>
#include <sys/dir.h>
#include <sys/param.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define FALSE 0
#define TRUE 1

extern int alphasort();

char pathname[MAXPATHLEN];

int file_select(struct direct *entry) {
    if ((strcmp(entry->d_name, ".") == 0) || (strcmp(entry->d_name, "..") == 0))
        return (FALSE);
    else
        return (TRUE);
}

int main() {
    int count, i;
    struct dirent **files;
    int file_select();

    if (getwd(pathname) == NULL) {
        printf("Error getting path\n");
        exit(0);
    }

    printf("Current Working Directory = %s\n", pathname);
    count = scandir(pathname, &files, file_select, alphasort);
    if (count <= 0) {
        printf("No files in this directory\n");
        exit(0);
    }

    printf("Number of files = %d\n", count);
    for (i = 1; i < count - 1; i++)
        printf("%s  \n", files[i - 1]->d_name);
    return 0;
}

/*
Student@ubuntu:~$ gcc list.c
Student@ubuntu:~$ ./a.out
Current working directory=/home/student/
Number of files=57
*/


/*
The program declares an external function alphasort(), which is used to sort the files alphabetically.

The program declares a character array to store the current working directory.

The program defines a function file_select() that takes a struct direct pointer as its argument. This function checks if the name of the file pointed to by the struct direct is either "." or "..", and returns FALSE if it is, TRUE otherwise.

The program declares variables count and i, and a pointer to a struct dirent called files. It also declares an external function file_select(). The program then uses getwd() to get the current working directory and store it in the pathname variable. If getwd() returns NULL, the program prints an error message and exits.


The program prints the current working directory, and then uses scandir() to scan the directory and store the names of all files (excluding "." and "..") in the files struct dirent pointer. scandir() uses file_select() to decide which files to include, and alphasort() to sort the files alphabetically. If scandir() returns a count less than or equal to 0, the program prints an error message and exits.



The program prints the number of files found, and then uses a for loop to print the name of each file in the files array. The loop starts from 1 and ends at count - 1, since files[0] is "." and files[count-1] is "..". Each file name is printed on a new line.
*/

