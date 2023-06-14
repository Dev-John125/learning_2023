// 1. Write a program to swap every alternate element of a given array starting for element 0
// For example, let's say we have a[5] = {10, 20, 30, 40, 50}, the result should be a[5] = {30, 20, 10, 40, 50}
// one more example a[5] = {10, 20, 30, 40, 50, 60}, the result should be a[5] = {30, 20, 10, 60, 50, 40}

#include <stdio.h>

void swapNum(int arr[], int size)
{   
    

    int i, temp;
    for(i =0; i < size - 2; i += 3)
    {
        temp = arr[i];
        arr[i] = arr[i+2];
        arr[i+2] = temp;
    }

}

void dispArray(int arr[], int size)
{
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int size, i;
    printf("Enter size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array: ");
    for(i = 0; i < size; i++)
        fscanf(stdin, "%d", &arr[i]);  // To take array input in a single line

    printf("Original Array\n");
    dispArray(arr, size);
    swapNum(arr, size);
    printf("\nModified Array\n");
    dispArray(arr, size);

    return 0;
}