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

int main(){
    char fp[128];
    char op;
    printf("Enter w for word count\n Enter l for line count\n Enter s for space count");
    scanf("%c", op);
    printf("Enter file path : " );
    scanf("%s", fp);
    return 0;
}





#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * file;
    char path[100];

    char ch;
    int characters, words, lines;


    printf("Enter source file path: ");
    scanf("%s", path);

    /* Open source files in 'r' mode */
    file = fopen(path, "r");


    /* Check if file opened successfully */
    if (file == NULL)
    {
        printf("\nUnable to open file.\n");
        exit(EXIT_FAILURE);
    }

    characters = words = lines = 0;
    while ((ch = fgetc(file)) != EOF)
    {
        characters++;

        /* Check new line */
        if (ch == '\n' || ch == '\0')
            lines++;

        /* Check words */
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
            words++;
    }

    /* Increment words and lines for last word */
    if (characters > 0)
    {
        words++;
        lines++;
    }

    /* Print file statistics */
    printf("\n");
    printf("Total characters = %d\n", characters);
    printf("Total words      = %d\n", words);
    printf("Total lines      = %d\n", lines);


    /* Close files to release resources */
    fclose(file);

    return 0;
}


