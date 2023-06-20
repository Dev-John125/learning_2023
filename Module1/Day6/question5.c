// 5. Write a program to demonstrate the swapping the fields of two structures using pointers

#include <stdio.h>
#include <string.h>

struct Student 
{
    char name[50];
    int age;
};

typedef struct Student stud;

void swapFields(stud *s1, stud *s2) 
{
    stud temp;

    strcpy(temp.name, s1->name);      // (destination, source)
    strcpy(s1->name, s2->name);
    strcpy(s2->name, temp.name);


    temp.age = s1->age;
    s1->age = s2->age;
    s2->age = temp.age;
}

int main() {
    stud student1, student2;

    // Student 1
    printf("Enter name for Student 1: ");
    fgets(student1.name, sizeof(student1.name), stdin);
    student1.name[strcspn(student1.name, "\n")] = '\0';  // Remove the trailing newline character


    printf("Enter age for Student 1: ");
    scanf("%d", &student1.age);

    getchar();  //To consume the newline chars

    printf("\n");

    // Student 2
    printf("Enter name for Student 2: ");
    fgets(student2.name, sizeof(student2.name), stdin);
    student2.name[strcspn(student2.name, "\n")] = '\0';  
    printf("Enter age for Student 2: ");
    scanf("%d", &student2.age);

    getchar();

    printf("Original:\n");
    printf("Student 1 - Name: %s, Age: %d\n", student1.name, student1.age);
    printf("Student 2 - Name: %s, Age: %d\n", student2.name, student2.age);
    printf("\n");

    // Swap the fields of student1 and student2
    swapFields(&student1, &student2);

    printf("Modified:\n");
    printf("Student 1 - Name: %s, Age: %d\n", student1.name, student1.age);
    printf("Student 2 - Name: %s, Age: %d\n", student2.name, student2.age);

    return 0;
}
