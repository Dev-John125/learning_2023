// 1. Assume User will be providing input in the form of a string as show below. 
// Write a function to parse the string and initialize an array of structures. 

// Example String : "1001 Aron 100.00" 
// Example Structure : 
//     struct Student{
//         int rollno;
//         char name[20];
//         float marks;
//     };

// Note: User must be able define the no. of inputs/size of the array during runtime.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student 
{
    int rollno;
    char name[20];
    float marks;
};

typedef struct Student stud;

void parseString(const char *, stud *, int);

void parseString(const char* inputStr, stud* students, int num) 
{
    const char* delimiter = " ";      // used to separate input string

    char* inputCopy = strdup(inputStr);  
    char* token = strtok(inputCopy, delimiter);   // separating roll number

    int i = 0;
    while (token != NULL && i < num) 
    {
        students[i].rollno = atoi(token);
        token = strtok(NULL, delimiter);         // separating name

        if (token != NULL) 
        {   
            // unsigned int length;
            strncpy(students[i].name, token, sizeof(students[i].name) - 1);
            students[i].name[sizeof(students[i].name) - 1] = '\0';
            token = strtok(NULL, delimiter);
        }

        if (token != NULL) 
        {
            students[i].marks = atof(token);   // seperating marks
            token = strtok(NULL, delimiter);
        }

        i++;
    }

    free(inputCopy);
}

int main() 
{
    int num, i;
    char inputString[100];

    printf("Enter the number of students: ");
    scanf("%d", &num);
    getchar();  // Consume the newline character

    stud* students = malloc(num * sizeof(stud));

    printf("Enter the student details:\n");
    for (i = 0; i < num; i++) 
    {   
        printf("Student %d: ",i + 1);
        fgets(inputString, sizeof(inputString), stdin);
        inputString[strcspn(inputString, "\n")] = '\0';   // to remove trailing newline character

        parseString(inputString, &students[i], num);
    }

    printf("\nStudent Details:\n");                     //Displaying student details
    for (i = 0; i < num; i++) 
    {
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    free(students);

    return 0;
}
