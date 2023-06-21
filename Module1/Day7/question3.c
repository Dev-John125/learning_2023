//3. Write a function to display all members in the above array of structures


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

//Function prototypes
void parseString(const char *, stud *, int);  // separate string and fill data
void initializeStudents(stud *, int);         // initialize structure
void displayStudents(stud *, int);            // display student details


void displayStudents(stud* students, int num) {
    
    for (int i = 0; i < num; i++) 
    {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}


void initializeStudents(stud* students, int num) 
{
    int i;

    for (i = 0; i < num; i++) 
    {
        students[i].rollno = 0;
        strcpy(students[i].name, "");
        students[i].marks = 0.0;
    }
}


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
    if (students == NULL) 
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    initializeStudents(students, num);


    printf("Enter the student details [roll-no. name marks]:\n");
    for (i = 0; i < num; i++) 
    {   
        printf("Student %d: ",i + 1);
        fgets(inputString, sizeof(inputString), stdin);
        inputString[strcspn(inputString, "\n")] = '\0';   // to remove trailing newline character

        parseString(inputString, &students[i], num);
    }

    printf("\n------------------");
    printf("\nStudent Details:\n\n");
    displayStudents(students, num);

    free(students);

    return 0;
}
