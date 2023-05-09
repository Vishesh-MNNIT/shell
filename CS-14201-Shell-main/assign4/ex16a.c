// cat UNIX

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[3]) {
    //Here, two variables are declared: fd is an integer that stores the file descriptor 
    //for the file being read, and i is an integer used to count the number of bytes read. 
    //buf is an array of characters that is used to read data from the file.
    int fd, i;
    char buf[2];
    //and the third argument 0777 specifies the permissions of the file. 
    //If the open() function returns -1, it means that an error occurred while opening the file.
    fd = open(argv[1], O_RDONLY, 0777);

    if (fd == -argc) {
        printf("Cannot Open Given File!\n");
    } else {
        //The read() function reads up to 1 byte of data from the file into the buf array.
        // The number of bytes read is stored in the variable i. The loop continues until read() returns 0,
        //indicating that the end of the file has been reached.
        while ((i = read(fd, buf, 1)) > 0) {
            printf("%c", buf[0]);
        }
        close(fd);
    }
    return 0;
}

/*
student@ubuntu:~$gcc –o prgcat.out prgcat.c
student@ubuntu:~$cat > ff
hello
hai
student@ubuntu:~$./prgcat.out ff
*/