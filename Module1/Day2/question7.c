// 2. W.A.P to compare the items in a box, assume equal size boxes
// Boxes shall have unique items stored in random order
// Boxes are compared True if there is one to one mapping of items
// return the final result 1 or 0

// Example of Equal Boxes:
// A[3] = {200, 10, -90}
// B[3] = {-90, 200, 10}    

// Example of Unequal Boxes:
// A[3] = {200, 9, -90}
// B[3] = {-90, 200, 10}    

// Note: The array should not be sorted

#include<stdio.h>

int compareBox( int boxA[], int boxB[], int size)
{
    int flag, i, j;

    for (i = 0; i < size; i++) 
    {
        flag = -1;
        for (j = 0; j < size; j++) 
        {
            if (boxA[i] == boxB[j]) 
            {
                flag = j;
                break;
            }
        }

        if (flag == -1) 
        {
            return 0; 
        }
    }

    return 1;
}

int main()
{
    int size, i, result;
    printf("Enter size of the box: ");
    scanf("%d", &size);

    int arr1[size];
    int arr2[size];

    printf("Enter the elements of the box 1: ");
    for(i = 0; i < size; i++)
        fscanf(stdin, "%d", &arr1[i]);

    printf("Enter the elements of the box 2: ");
    for(i = 0; i < size; i++)
        fscanf(stdin, "%d", &arr2[i]);

    result = compareBox(arr1, arr2, size);

    if(result)
        printf("One to One Mapping exists\n");
    else 
        printf("Mapping doesnt exist\n");

    return 0;
}