// 2. Write a function to return the grade of the given student using switch case statements
// 90 to 100 -> 'A'
// 75 to 89 -> 'B'
// 60 to 74 -> 'C'
// 50 to 59 -> 'D'
// 36 to 49 -> 'E'
// 0 to 35 -> 'F'

// In main check the return value and print the below
// 65 -> "Grade A"
// 66 -> "Grade B"
// 67 -> "Grade C"
// 68 -> "Grade D"
// 69 -> "Grade E"
// 70 -> "Grade F"


#include<stdio.h>

char grade(int marks) 
{
    char grade;

    switch (marks)
    {
        case 90 ... 100:    // ... operator is used to allow range matching in C
            grade = 'A';
            break;

        case 75 ... 89:
            grade = 'B';
            break;
        
        case 60 ... 74:
            grade = 'C';
            break;
        
        case 50 ... 59:
            grade = 'D';
            break;

        case 36 ... 49:
            grade = 'E';
            break;
        
        case 0 ... 35:
            grade = 'F';
            break;
        
        default:
            grade = 'Z';    // Z is used to show invalid score
            break;

    }

    return grade;
}

int main()
{
    int marks;
    char result;
    printf("Enter total marks of a student to calculate grade: ");
    scanf("%d", &marks);
    result = grade(marks);

    if(result == 'Z')
    {
        printf("Invalid Marks\n");
    }
    else
    {
        printf("Grade %c\n", result);
    }

    return 0;
}