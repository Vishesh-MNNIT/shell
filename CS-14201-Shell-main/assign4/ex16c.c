// mv UNIX

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int i, fd1, fd2;
    char *file1, *file2, buf[2];
    file1 = argv[1];
    file2 = argv[2];

    printf("file1=%s\nfile2=%s\n", file1, file2);
    fd1 = open(file1, O_RDONLY, 0777);
    fd2 = creat(file2, 0777);
    while (read(fd1, buf, 1) > 0)
        write(fd2, buf, 1);

    remove(file1);
    close(fd1);
    close(fd2);
    return 0;
}

/*
student@ubuntu:~$gcc –o mvp.out mvp.c
student@ubuntu:~$cat > ff
hello
hai
student@ubuntu:~$./mvp.out ff ff1
student@ubuntu:~$cat  ff
cat:ff:No such file or directory
student@ubuntu:~$cat ff1
*/

/*
int i, fd1, fd2;: This line declares three integer variables.
char *file1, *file2, buf[2];: This line declares two character pointers and an array of two characters.
file1 = argv[1];: This line assigns the value of the second command-line argument to the file1 variable.
file2 = argv[2];: This line assigns the value of the third command-line argument to the file2 variable.
printf("file1=%s\nfile2=%s\n", file1, file2);: This line prints the names of the two files.
fd1 = open(file1, O_RDONLY, 0777);: This line opens the first file with read-only access and assigns the file descriptor to fd1.
fd2 = creat(file2, 0777);: This line creates the second file with write-only access and assigns the file descriptor to fd2.
while (read(fd1, buf, 1) > 0) write(fd2, buf, 1);: This line reads the first file one character at a time and writes it to the second file.
remove(file1);: This line deletes the first file.
close(fd1);: This line closes the first file.
close(fd2);: This line closes the second file.
*/