#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readFile(char* filename)
{
	//  declares a pointer to a FILE object called fp, which will be used to represent the file being read.
	FILE *fp = fopen(filename, "r+"); 

	//used to hold each character read from the file.
	char ch;
	// used to count the number of spaces in the file.
	int c=0;

	if(fp == NULL) printf("File not found!");
	else
	{
		// reads each character from the file using the fgetc function 
		//until the end of file (EOF) is reached.
		while ((ch = fgetc(fp)) != EOF) 
    	{
        	if(ch == ' ')
            	++c;
    	}
	}
	fclose(fp);
	return c;
}

int main(int argc, char** argv)
{
	printf("Spaces = %d\n", readFile(argv[1]));
	return 0;
}