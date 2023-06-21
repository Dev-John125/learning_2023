// 2. Case Handler:
// Write a C program to copy a file by considering the user argument to handle the text case
// -u, to change file content to Upper Case
// -l, to change file content to Lower Case
// -s, to change file content to Sentence Case                  // Title case 
// if no arguments are passed then it should be a normal copy

// Example, say we have a file f1 with the following content
// f1:
// -----------------------
// This is the file data
// testing Case copy
// application
// -----------------------

// ./cp -s f1 f2
// f2:
// -----------------------
// This Is The File Data             // Title case
// Testing Case Copy
// Application
// -----------------------

// ./cp -l f1 f3
// f3:
// -----------------------
// this is the file data
// testing case copy
// application
// -----------------------

// ./cp -u f1 f4
// f4:
// -----------------------
// THIS IS THE FILE DATA
// TESTING CASE COPY
// APPLICATION
// -----------------------

// ./cp f1 f5
// Should perform a normal copy

// ------------------------------------------------------------------------------------------------------------------------------------


// To pass command-line arguments, we typically define main() with two arguments: 
// the first argument is the number of command-line arguments 
// and the second is a list of command-line arguments.
// int main(int argc, char *argv[]) { /* ... */ }

// Reference : https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void copyFile(FILE *source, FILE *destination, char *argument) 
{
    char ch;
    int capital = 1;
    int to_upper = 0, to_lower = 0, to_sentence = 0;

    if (argument != NULL) 
    {
        if (strcmp(argument, "-u") == 0) 
        {
            to_upper = 1;
        } 
        else if (strcmp(argument, "-l") == 0) 
        {
            to_lower = 1;
        } 
        else if (strcmp(argument, "-s") == 0) 
        {
            to_sentence = 1;
        } 
        else 
        {
            printf("Invalid argument: %s\n", argument);
            exit(0);
        }
    }
    else
    {
        while ((ch = fgetc(source)) != EOF) 
        {
            fputc(ch, destination);
        }
        return;
    }


    while ((ch = fgetc(source)) != EOF) 
    {
        if (to_upper) 
        {
            ch = toupper(ch);
        } 
        else if (to_lower) 
        {
            ch = tolower(ch);
        } 
        else if (to_sentence)                           // Title case logic written here instead of sentence case, refer to examples above 
        {   
            
            if (isalpha(ch) && capital) 
            {
                ch = toupper(ch);
                capital = 0;
            } 
            else if (!isalpha(ch) && !isspace(ch))      // In case of symbols like ?, !, % , etc.
            {
                capital = 1;
            }
            else if (isspace(ch)) 
            {
                capital = 1;
            }
            else
            {
                ch = tolower(ch);
            }
        }
        fputc(ch, destination);
    }
}

int main(int argc, char *argv[]) 
{
    FILE *source, *destination;
    char *argument;
    char sourceFileName[100],destinationFileName[100];

    if (argc < 2 || argc > 4) 
    {
        printf("Wrong format\n");
        printf("Usage: ./a.out <argument> <source_file> <destination_file>\n");
        printf("Argument can be left blank for simple file copy purposes\n");
        return 1;
    }
    else if (argc == 3)
    {
        argument = NULL;
        strcpy(sourceFileName, argv[1]);
        strcpy(destinationFileName, argv[2]);
    }
    else
    {
        argument = argv[1];
        strcpy(sourceFileName, argv[2]);
        strcpy(destinationFileName, argv[3]);
    }

    

    source = fopen(sourceFileName, "r");
    if (source == NULL) 
    {
        printf("Failed to open the file.\n");
        return 2;
    }

    destination = fopen(destinationFileName, "w");
    if (destination == NULL) 
    {
        printf("Failed to create the file.\n");
        return 2;
    }

    copyFile(source, destination, argument);

    printf("File copied successfully\n");

    fclose(source);
    fclose(destination);

    return 0;
}
