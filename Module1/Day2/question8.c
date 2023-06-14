// 3. Suppose 7 names are stored in an array of pointers names[] as shown below:
//  char *name[]={
//         "Santosh", "Amol", "Santosh Jain", "Kishore", "Rahul", "Amolkumar", "Hemant"
//           }
//   Write a program to arrange these names in alphabetical order.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sortNames(char *names[], int size) 
{
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = i + 1; j < size; j++) 
        {
            if (strcmp(names[i], names[j]) > 0) 
            {
                char *temp = names[i];
                names[i] = names[j];
                names[j] = temp;
            }
        }
    }
}

int main() 
{   
    int size, i;
    printf("Enter the number of names: ");
    scanf("%d", &size);

    char *names[size];

    printf("Enter the names: \n");
    for (i = 0; i < size; i++)
    {
        names[i] = malloc(100 * sizeof(char));
        scanf("%s", names[i]);
    }

    // char *names[] = {
    //     "Santosh", "Amol", "Santosh Jain", "Kishore", "Rahul", "Amolkumar", "Hemant"
    // };
    // int size = sizeof(names) / sizeof(names[0]);

    printf("Before Sorting:\n");
    for (int i = 0; i < size; i++) 
    {
        printf("%s\n", names[i]);
    }

    sortNames(names, size);

    printf("\nAfter Sorting:\n");
    for (int i = 0; i < size; i++) 
    {
        printf("%s\n", names[i]);
    }

    return 0;
}
