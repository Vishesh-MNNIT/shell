#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readFile(char *filename, char *mode) {
    FILE *fp = fopen(filename, "r+");
    char ch;
    int wc = 0, lc = 0, sp = 0;

    if (fp == NULL) {
        printf("File not found!\n");
        return;
    } else {
        while ((ch = fgetc(fp)) != EOF) {
            if(ch == '\n')
                lc++;
            if (ch == ' ')
                sp++;
        }
    }
    wc = sp + lc;
    fclose(fp);

    switch (*mode) {
        case 'w':
            printf("Words = %d\n", wc);
            break;
        case 'l':
            printf("Lines = %d\n", lc);
            break;
        case 's':
            printf("Spaces = %d\n", sp);
            break;
        default :
            printf("%c is an Invalid Choice\n", *mode);
    }
}

int main(int argc, char *argv[]) {
    readFile(argv[1], argv[2]);
    return 0;
}

