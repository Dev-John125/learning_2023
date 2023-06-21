// 1. File Copy: Write a C program to copy a file using file operations 

#include <stdio.h>

int main() 
{
    FILE *source, *destination;
    char fileName[50];
    char ch;

    printf("Enter the file name to read: ");
    scanf("%s", fileName);

    source = fopen(fileName, "r");
    if (source == NULL) 
    {
        printf("Failed to open the file\n");
        return 2;
    }

    printf("Enter the file name to write: ");
    scanf("%s", fileName);

    destination = fopen(fileName, "w");
    if (destination == NULL) 
    {
        printf("Failed to create file\n");
        return 2;
    }

    while ((ch = fgetc(source)) != EOF) 
    {
        fputc(ch, destination);
    }

    printf("File copied successfully\n");


    fclose(source);
    fclose(destination);

    return 0;
}
