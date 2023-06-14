// 2. Write a program to print the grade of the given student using if else if block
//     - 90 to 100 -> "Grade A"
//     - 75 to 89 -> "Grade B"
//     - 60 to 74 -> "Grade C"
//     - 50 to 59 -> "Grade D"
//     - 0 to 49 -> "Grade F"

#include<stdio.h>
#include<stdlib.h>

char grade(int marks)
{
    char result;

    if(marks >= 90 && marks <= 100)
    {
        result = 'A';
    }
    else if(marks >= 75 && marks <= 89)
    {
        result = 'B';
    }
    else if(marks >= 60 && marks <= 74)
    {
        result = 'C';
    }
    else if(marks >= 50 && marks <= 59)
    {
        result = 'D';
    }
    else if(marks >= 0 && marks <= 49)
    {
        result = 'F';
    }
    else
    {
        printf("Invalid Marks\n");
        exit(0);
    }

    return result;
}


int main()
{
    int marks;
    printf("Enter the total marks of a Student: ");
    scanf("%d", &marks);

    printf("Grade: %c\n", grade(marks));

    return 0;
}