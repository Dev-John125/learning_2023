// 4. Write a program to Store Data for n students in Structures Dynamically. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student 
{
    char name[30];
    int age;
    float percentage;
};

typedef struct Student student;

int main() 
{
    int n, i;
    student *ptr;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    ptr = (student *)malloc(n * sizeof(student));   // DMA

    if (ptr == NULL) 
    {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }


    for (i = 0; i < n; i++) 
    {
        printf("\nEnter details for student %d:\n", i + 1);
        getchar();   //To consume the newline chars

        printf("Name: ");
        fgets(ptr[i].name, sizeof(ptr[i].name), stdin);

        printf("Age: ");
        scanf("%d", &ptr[i].age);

        printf("Percentage: ");
        scanf("%f", &ptr[i].percentage);

        printf("\n");
    }

    printf("----------------------------\n");
    printf("Data stored for %d students:\n", n);
    getchar();

    for (i = 0; i < n; i++) 
    {
        printf("Name: %s", ptr[i].name);
        printf("Age: %d\n", ptr[i].age);
        printf("Percentage secured: %.2f\n", ptr[i].percentage);
        printf("\n\n");
    }

    // Free the dynamically allocated memory
    free(ptr);
    ptr = NULL;

    return 0;
}
