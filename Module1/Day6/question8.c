// 3. Implement structures to read, write and compute average-marks and display the students scoring above
//    and below the average marks for a class of N students.


#include<stdio.h>
#include<string.h>

typedef struct
{
    char name[50];
    float marks;
} student;

void readStudents(student s[], int n)
{
    int i;
    printf("Enter the Student details: \n");
    for(i = 0; i < n; i++)
    {
        printf("Student %d:\n", i + 1);
        printf("Enter Name: ");
        scanf(" %[^\n]s", s[i].name);
        printf("Enter Marks: ");
        scanf("%f", &s[i].marks);
    }
}


void displayStudents(student s[], int n) 
{
    int i;
    printf("Details of the students:\n");
    for (i = 0; i < n; i++) 
    {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", s[i].name);
        printf("Marks: %.2f\n", s[i].marks);
        printf("\n");
    }
}


float computeAvg(student s[], int n) 
{
    float sum = 0.0;
    int i;

    for (i = 0; i < n; i++) 
    {
        sum += s[i].marks;
    }
    return sum / n;
}

void printBasedOnAvg(student s[], int n, int option) 
{
    float average = computeAvg(s, n);
    int i;
    if(option == 1)
    {
        printf("The students who scored above the average marks:\n");
        for (i = 0; i < n; i++) 
        {
            if (s[i].marks > average) 
            {
                printf("%s\n", s[i].name);
            }
        }
    }
    else if (option == 2)
    {
        printf("\nThe students who scored below the average marks:\n");
        for (i = 0; i < n; i++) 
        {
            if (s[i].marks < average) 
            {
                printf("%s\n", s[i].name);
            }
        }
    }
}

int main() 
{
    int n, option;
    student s[40];
    float average;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    readStudents(s, n);
    printf("\n");

    printf("Chose one of the given options:\n");
    printf("1.Display all students\n");
    printf("2.Display Average marks\n");
    printf("3.Display Students who scored above average\n");
    printf("4.Display Students who scored below average\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    switch(option)
    {
        case 1:
            displayStudents(s, n);
            printf("\n");
            break;

        case 2:
            average = computeAvg(s, n);
            printf("The average marks of the class is %.2f\n", average);
            break;
        case 3:
            average = computeAvg(s, n);
            printBasedOnAvg(s, n, 1);
            printf("\n");
            break;
        case 4:
            average = computeAvg(s, n);
            printBasedOnAvg(s, n, 2);
            printf("\n");
            break;
        default:
            printf("Invalid Choice\n");
            return 1;
    }
    return 0;
}