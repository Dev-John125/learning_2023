// 3. Write a program to read the 
//     - Roll No
//     - Name (Note, you should read full name of the student including initials)
//     - Marks of Physics, Math and Chemistry
//     Calculate the total, percentage and print the summary.

#include<stdio.h>

typedef struct{
    int rollNo;
    char name[50];
    float phyMarks;
    float mathMarks;
    float chemMarks;
}Student;

float calculateTotalMarks(float phyMarks, float mathMarks, float chemMarks)
{
    return phyMarks + mathMarks + chemMarks;
}

float calculatePercentage(float totalMarks)
{
    return totalMarks / 3;
}

void printSummary (Student s1)
{   
    float total = calculateTotalMarks(s1.phyMarks, s1.mathMarks, s1.chemMarks);

    printf("\nRoll Number     :%d\n", s1.rollNo);
    printf("Name            :%s\n", s1.name);
    printf("Physics Marks   :%.2f\n", s1.phyMarks);
    printf("Chemistry Marks :%.2f\n", s1.chemMarks);
    printf("Maths Marks     :%.2f\n", s1.mathMarks);
    printf("Total Marks     :%.2f\n", total);
    printf("Percentage      :%.2f%%\n", calculatePercentage(total));
}

int main()
{
    Student s1;
    printf("Enter Roll No: ");
    scanf("%d", &s1.rollNo);

    printf("Enter Name: ");
    scanf(" %[^\n]s", s1.name);

    printf("Enter Marks of Physics: ");
    scanf("%f", &s1.phyMarks);

    printf("Enter Marks of Math: ");
    scanf("%f", &s1.mathMarks);

    printf("Enter Marks of Chemistry: ");
    scanf("%f", &s1.chemMarks);

    printSummary(s1);

    return 0;
}